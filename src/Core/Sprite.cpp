#include "Core/Sprite.hpp"

namespace Core {
    Sprite::Sprite(sf::Vector2f position, sf::Vector2f size, sf::Color colour, sf::Texture texture) : GameObject(position, size, colour) {
        this->texture = texture;
        setSprite();
    }

    Sprite::Sprite(sf::Vector2f position, sf::Vector2f size, sf::Color colour, std::string textureFile) : GameObject(position, size, colour) {
        if (!this->texture.loadFromFile(textureFile))
            printf("Sprite with file [%s] could not be loaded\n", textureFile.c_str());

        setSprite();
    }

    void Sprite::setSprite() {
        this->sprite.setPosition(this->pos);
        this->sprite.setScale(this->size);
        this->sprite.setTexture(this->texture);
    }

    sf::Drawable* Sprite::getDrawable() {
        return &this->sprite;
    }

    void Sprite::update() {}
}