//
// Created by alwin on 11/9/22.
//
#include "Core/GameObject.hpp"

namespace Core {
    GameObject::GameObject(sf::Vector2f position, sf::Vector2f size, sf::Color colour) {
        this->pos = position;
        this->size = size;
        this->colour = colour;
    }

    void GameObject::update() {}

    sf::Drawable* GameObject::getDrawable() {}

    sf::Vector2f GameObject::getPosition() {
        return this->pos;
    }

    sf::Vector2f GameObject::getSize() {
        return this->size;
    }
}