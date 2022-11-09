//
// Created by alwin on 11/9/22.
//

#pragma once

#include "Button.hpp"
#include "Entity.hpp"

namespace Buttons {
    class HealButton : public Core::Button {
    public:
        HealButton(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size, sf::Color colour, sf::Color hoverColour, const std::string &text);
        void heal(Entity* entity);
    };
}
