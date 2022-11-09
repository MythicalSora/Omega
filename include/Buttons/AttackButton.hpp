//
// Created by alwin on 11/9/22.
//

#pragma once

#include "Button.hpp"
#include "Entity.hpp"

namespace Buttons {
class AttackButton : public Core::Button {
public:
    AttackButton(sf::RenderWindow* window, sf::Vector2f position, sf::Vector2f size, sf::Color colour, sf::Color hoverColour, const std::string &text);
    void attack(Entity* target, Entity* user);

private:
    float getBaseDamage(Entity* player, Entity* target);
    float randomiseDamage(float damage);
};
}
