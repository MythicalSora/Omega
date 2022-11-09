//
// Created by alwin on 11/9/22.
//
#include "Core/Button.hpp"

namespace Core {
    Button::Button(sf::Vector2f position, sf::Vector2f size, sf::Color colour, sf::Color hoverColour,
                   const std::string &text) : GameObject(position, size) {
        this->pos = position;
        this->size = size;
        this->colour = colour;
        this->hoverColour = hoverColour;
        this->text.setString(text);

        this->rect.setPosition(this->pos);
        this->rect.setSize(this->size);
        this->rect.setFillColor(this->colour);
        this->rect.setOutlineColor(sf::Color::Black);
    }

    void Button::onClick() {}

    void Button::update() {}

    sf::Drawable* Button::getDrawable() {
        return &this->rect;
    }
}