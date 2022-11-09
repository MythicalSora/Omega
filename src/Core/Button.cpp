//
// Created by alwin on 11/9/22.
//
#include "Core/Button.hpp"
#include "Scene.hpp"
#include "SFML/Window/Mouse.hpp"

namespace Core {
    Button::Button(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size, sf::Color colour, sf::Color hoverColour,
                   const std::string &text) : GameObject(position, size) {
        this->window = window;
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

    void Button::onClick() {
        if (isClicked()) {
            printf("I clicked a button and my weird function call works\n");
        }
    }

    void Button::update() {
        onClick();
    }

    sf::Drawable* Button::getDrawable() {
        return &this->rect;
    }

    bool Button::isHovered() {
        if (this->rect.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*this->window))) {
            this->rect.setFillColor(this->hoverColour);
            return true;
        }

        this->rect.setFillColor(this->colour);
        return false;
    }

    bool Button::isClicked() {
        return (isHovered() && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left));
    }
}