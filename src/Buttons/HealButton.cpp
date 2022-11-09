//
// Created by alwin on 11/9/22.
//
#include "Buttons/HealButton.hpp"

namespace Buttons {
    HealButton::HealButton(sf::RenderWindow *window, sf::Vector2f position, sf::Vector2f size, sf::Color colour,
                               sf::Color hoverColour, const std::string &text) : Core::Button(window, position, size, colour, hoverColour, text) {}

    void HealButton::heal(Entity *entity) {
        float healing = 10;
        //healing calc

        entity->updateHp("add", healing);
        printf("Healed entity by %f\n", healing);
    }
}