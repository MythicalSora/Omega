#pragma once

#include "Core/GameObject.hpp"
#include "SFML/Graphics/Sprite.hpp"
namespace Core {
    class Sprite : GameObject {
    private:
        sf::Sprite sprite;

    public:
        Sprite(sf::Vector2f position, sf::Vector2f size, sf::Color colour, sf::Texture texture);
        Sprite(sf::Vector2f position, sf::Vector2f size, sf::Color colour, std::string textureFile);
        sf::Drawable* getDrawable() override;
        void update() override;
    };
}
