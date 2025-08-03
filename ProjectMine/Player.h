#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "Obstacle.h"
#include <vector>

class Player : public GameObject {
    sf::RectangleShape shape;
    float velocityX, velocityY;
    const float speed, jumpSpeed, gravity;
    bool onGround;
    const std::vector<Obstacle*>& obstacles;

public:
    Player(const std::vector<Obstacle*>& obs);
    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;
    sf::FloatRect getBounds() const override;
};

#endif // PLAYER_H

