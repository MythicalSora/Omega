//
// Created by alwin on 11/9/22.
//

#include "Buttons/SceneButton.hpp"

namespace Buttons {
    SceneButton::SceneButton(Utilities::SceneType scene, sf::RenderWindow *window, sf::Vector2f position,
                             sf::Vector2f size, sf::Color colour, sf::Color hoverColour, const std::string &text) : Core::Button(window, position, size, colour, hoverColour, text) {
        this->scene = scene;
    }
}