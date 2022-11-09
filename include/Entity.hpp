//
// Created by alwin on 11/9/22.
//

#pragma once

#include "Sprite.hpp"

class Entity : Core::Sprite {
protected:
    float hp;
    float attack;
    float defense;

public:
    Entity(float hp, float attack, float defense, sf::Vector2f position, sf::Vector2f size, sf::Color colour, std::string textureFile);

    float getHp();
    float getAttack() const;
    float getDefense() const;

    void updateHp(std::string operation, float value);
};
