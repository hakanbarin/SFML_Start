#include "Game.h"

Game::Game()
    : window({ 800,600 }, "OOP SFML Oyunu")
{
    // Zemin
    obstacleStorage.emplace_back(
        sf::Vector2f(800.f, 100.f),
        sf::Vector2f(0.f, 500.f),
        sf::Color::Green
    );

    // 1. bariyer
    obstacleStorage.emplace_back(
        sf::Vector2f(100.f, 50.f),
        sf::Vector2f(300.f, 450.f),
        sf::Color::Red
    );

    // 2. bariyer
    obstacleStorage.emplace_back(
        sf::Vector2f(100.f, 50.f),
        sf::Vector2f(500.f, 350.f),
        sf::Color::Magenta
    );


    for (auto& o : obstacleStorage)
        obstacles.push_back(&o);

    player = new Player(obstacles);
}

Game::~Game() {
    delete player;
}

void Game::run() {
    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();
        handleEvents();
        player->update(dt);

        window.clear();
        for (auto& o : obstacleStorage) o.draw(window);
        player->draw(window);
        window.display();
    }
}

void Game::handleEvents() {
    sf::Event ev;
    while (window.pollEvent(ev)) {
        if (ev.type == sf::Event::Closed)
            window.close();
        if (ev.type == sf::Event::MouseButtonPressed
            && ev.mouseButton.button == sf::Mouse::Left)
        {
            // örnek hamle kodunu buraya taþý
            // player->moveHamle(); gibi bir metot ekleyebilirsin
        }
    }
}
