//
// Created by alwin on 11/9/22.
//

#pragma once

#include "Button.hpp"
#include "Utilities.hpp"

namespace Buttons {
    class SceneButton : public Core::Button {
    public:
        Utilities::SceneType scene;
    public:
        SceneButton(Utilities::SceneType scene, sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size, sf::Color colour, sf::Color hoverColour, const std::string &text);
    };
}
