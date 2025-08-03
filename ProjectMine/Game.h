#pragma once
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Obstacle.h"
#include "Player.h"
#include <vector>

class Game {
    sf::RenderWindow window;
    sf::Clock clock;

    std::vector<Obstacle>   obstacleStorage;
    std::vector<Obstacle*>  obstacles;
    Player* player;

public:
    Game();
    ~Game();
    void run();

private:
    void handleEvents();
};

#endif // GAME_H

