#pragma once
#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "GameObject.h"


class Obstacle : public GameObject {
    sf::RectangleShape shape;
public:

    Obstacle(const sf::Vector2f& size,
        const sf::Vector2f& pos,
        const sf::Color& color);

    void update(float) override;
    void draw(sf::RenderWindow& window) override;
    sf::FloatRect getBounds() const override;
};

#endif // OBSTACLE_H
