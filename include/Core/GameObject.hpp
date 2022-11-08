#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace Core {
    class GameObject {
    private:
        std::string id;

    public:
        sf::Vector2f pos;
        sf::Vector2f size;
        sf::Color colour;

    public:
        GameObject(sf::Vector2f position, sf::Vector2f size, sf::Color colour = sf::Color::Transparent);
        virtual void update();
        virtual sf::Drawable* getDrawable();
    };
}