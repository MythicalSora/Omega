#pragma once

#include <Core/GameObject.hpp>

namespace Core {
    GameObject::GameObject(sf::Vector2f position, sf::Texture texture) {
        hasSprite = true;

        sprite = sf::Sprite(texture);
        sprite.setPosition(position);
    }

    GameObject::GameObject(sf::Vector2f position, sf::Vector2f size, sf::Color colour) {
		rect.setPosition(position);
		rect.setSize(size);
		rect.setFillColor(colour);
	}

	sf::Drawable GameObject::drawable()
	{
        if (!hasSprite) return rect;
        return sprite;
	}
}