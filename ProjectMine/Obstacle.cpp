



#include "Obstacle.h"

Obstacle::Obstacle(const sf::Vector2f& size,
    const sf::Vector2f& pos,
    const sf::Color& color)
{
    shape.setSize(size);
    shape.setPosition(pos);
    shape.setFillColor(color);
}

void Obstacle::update(float) { /* sabit obje, boþ */ }

void Obstacle::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::FloatRect Obstacle::getBounds() const {
    return shape.getGlobalBounds();
}
