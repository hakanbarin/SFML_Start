#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>

class GameObject {
public:
    virtual ~GameObject() = default;
    virtual void update(float dt) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual sf::FloatRect getBounds() const = 0;
};

#endif // GAMEOBJECT_H
