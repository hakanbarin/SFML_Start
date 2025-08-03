#include "Player.h"
#include <SFML/Window/Keyboard.hpp>

Player::Player(const std::vector<Obstacle*>& obs)
    : velocityX(0.f), velocityY(0.f),
    speed(200.f), jumpSpeed(450.f), gravity(981.f),
    onGround(false), obstacles(obs)
{
    shape.setSize({ 50,100 });
    shape.setFillColor(sf::Color::Cyan);
    shape.setPosition({ 100,400 });
}

void Player::update(float dt) {
    // 1) Input
    velocityX = 0.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) velocityX = speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  velocityX = -speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && onGround) {
        velocityY = -jumpSpeed; onGround = false;
    }

    // 2) Gravity
    velocityY += gravity * dt;

    // 3) Horizontal
    float dx = velocityX * dt;
    shape.move(dx, 0);
    for (auto* obs : obstacles) {
        if (getBounds().intersects(obs->getBounds())) {
            if (dx > 0)
                shape.setPosition(
                    obs->getBounds().left - getBounds().width,
                    shape.getPosition().y);
            else if (dx < 0)
                shape.setPosition(
                    obs->getBounds().left + obs->getBounds().width,
                    shape.getPosition().y);
        }
    }

    // 4) Vertical
    float dy = velocityY * dt;
    shape.move(0, dy);
    for (auto* obs : obstacles) {
        if (getBounds().intersects(obs->getBounds())) {
            if (dy > 0) { // fall
                shape.setPosition(
                    shape.getPosition().x,
                    obs->getBounds().top - getBounds().height);
                velocityY = 0; onGround = true;
            }
            else if (dy < 0) { // jump
                shape.setPosition(
                    shape.getPosition().x,
                    obs->getBounds().top + obs->getBounds().height);
                velocityY = 0;
            }
        }
    }
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::FloatRect Player::getBounds() const {
    return shape.getGlobalBounds();
}
