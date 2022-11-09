#pragma once

#include "GameObject.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

namespace Core {
    class Button : public GameObject {
    private:
        bool beingClicked = false;
        sf::RectangleShape rect;
        sf::RenderWindow* window;
    public:
        sf::Text text;
        sf::Color colour;
        sf::Color hoverColour;

    public:
        Button(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size, sf::Color colour, sf::Color hoverColour, const std::string &text);
        virtual void onClick();
        void update() override;
        sf::Drawable* getDrawable() override;
        bool isHovered();
        bool isClicked();
    };
}