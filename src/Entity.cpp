#include "Entity.hpp"

//
// Created by alwin on 11/9/22.
//
Entity::Entity(float hp, float attack, float defense, sf::Vector2f position, sf::Vector2f size, sf::Color colour,
               std::string textureFile) : Core::Sprite(position, size, colour, textureFile) {
    this->hp = hp;
    this->attack = attack;
    this->defense = defense;
}

float Entity::getHp() {
    return this->hp;
}

float Entity::getAttack() const {
    return this->attack;
}

float Entity::getDefense() const {
    return this->defense;
}

void Entity::updateHp(std::string operation, float value) {
    if (operation == "add")
        this->hp += value;
    else if (operation == "subtract") {
        this->hp -= value;
    }
}

