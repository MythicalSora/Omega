#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace Core {
    class GameObject {
        private:
            std::string id;
        
        protected:
            sf::RectangleShape rect;
        
        public:
            GameObject(sf::Vector2f position, sf::Vector2f size, sf::Color colour = sf::Color::Transparent);

            virtual sf::RectangleShape drawable();
    };
}