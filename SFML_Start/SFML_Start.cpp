
#include "Game.h"

int main() 
{
    //Init game engine

    Game game;

    game.run();



    return 0;
}








































/*
int main()
{
    sf::RenderWindow window({ 800,600 }, "SFML Ziplama ve Coklu Barrier");

    // Player, ground ve barrier’lar
    sf::RectangleShape player({ 50,100 });
    player.setFillColor(sf::Color::Cyan);
    player.setPosition(100, 400);

    sf::RectangleShape ground({ 800,100 });
    ground.setFillColor(sf::Color::Green);
    ground.setPosition(0, 500);

    sf::RectangleShape barrier1({ 100,50 });
    barrier1.setFillColor(sf::Color::Red);
    barrier1.setPosition(300, 450);

    // Ýkinci barrier, daha yukarýda
    sf::RectangleShape barrier2({ 100,50 });
    barrier2.setFillColor(sf::Color::Magenta);
    barrier2.setPosition(500, 350);

    // Fizik parametreleri
    float velocityX = 0.f;
    float velocityY = 0.f;
    const float speed = 200.f;   // px/s
    const float jumpSpeed = 450.f;   // px/s
    const float gravity = 981.f;   // px/s^2
    bool onGround = false;

    sf::Clock clock;
    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();

        // --- Event Ýþlemleri ---
        sf::Event ev;
        while (window.pollEvent(ev))
        {
            if (ev.type == sf::Event::Closed)
                window.close();

            // Hamle (mouse týk) varsa…
            if (ev.type == sf::Event::MouseButtonPressed
                && ev.mouseButton.button == sf::Mouse::Left)
            {
                player.move(150.f, 0.f);
            }
        }

        // --- Girdi ve Yerçekimi ---
        velocityX = 0.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            velocityX = speed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            velocityX = -speed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && onGround)
        {
            velocityY = -jumpSpeed;
            onGround = false;
        }
        velocityY += gravity * dt;

        // --- Hareket ve Çarpýþma ---
        // 1) Yatay hareket
        float dx = velocityX * dt;
        player.move(dx, 0);

        // Yatay çarpýþma kontrolü: barrier1
        if (player.getGlobalBounds().intersects(barrier1.getGlobalBounds()))
        {
            if (dx > 0)
                player.setPosition(barrier1.getPosition().x - player.getSize().x,
                    player.getPosition().y);
            else if (dx < 0)
                player.setPosition(barrier1.getPosition().x + barrier1.getSize().x,
                    player.getPosition().y);
        }
        // barrier2 için de ayný kontrol
        if (player.getGlobalBounds().intersects(barrier2.getGlobalBounds()))
        {
            if (dx > 0)
                player.setPosition(barrier2.getPosition().x - player.getSize().x,
                    player.getPosition().y);
            else if (dx < 0)
                player.setPosition(barrier2.getPosition().x + barrier2.getSize().x,
                    player.getPosition().y);
        }

        // 2) Dikey hareket
        float dy = velocityY * dt;
        player.move(0, dy);

        // Dikey çarpýþma kontrolü: barrier1
        if (player.getGlobalBounds().intersects(barrier1.getGlobalBounds()))
        {
            if (dy > 0) // düþerken
            {
                player.setPosition(player.getPosition().x,
                    barrier1.getPosition().y - player.getSize().y);
                velocityY = 0; onGround = true;
            }
            else if (dy < 0) // zýplarken
            {
                player.setPosition(player.getPosition().x,
                    barrier1.getPosition().y + barrier1.getSize().y);
                velocityY = 0;
            }
        }
        // barrier2 için de ayný dikey kontrol
        if (player.getGlobalBounds().intersects(barrier2.getGlobalBounds()))
        {
            if (dy > 0)
            {
                player.setPosition(player.getPosition().x,
                    barrier2.getPosition().y - player.getSize().y);
                velocityY = 0; onGround = true;
            }
            else if (dy < 0)
            {
                player.setPosition(player.getPosition().x,
                    barrier2.getPosition().y + barrier2.getSize().y);
                velocityY = 0;
            }
        }

        // 3) Zemin çarpýþmasý
        float bottom = player.getPosition().y + player.getSize().y;
        if (bottom > ground.getPosition().y)
        {
            player.setPosition(player.getPosition().x,
                ground.getPosition().y - player.getSize().y);
            velocityY = 0; onGround = true;
        }

        // --- Çizim ---
        window.clear();
        window.draw(player);
        window.draw(ground);
        window.draw(barrier1);
        window.draw(barrier2);
        window.display();
    }

    return 0;
}

*/