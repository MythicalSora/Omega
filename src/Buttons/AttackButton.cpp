//
// Created by alwin on 11/9/22.
//
#include <cmath>
#include "Buttons/AttackButton.hpp"
#include "Utilities.hpp"

namespace Buttons {
    AttackButton::AttackButton(sf::RenderWindow *window, sf::Vector2f position, sf::Vector2f size, sf::Color colour,
                               sf::Color hoverColour, const std::string &text) : Core::Button(window, position, size, colour, hoverColour, text) {}

    void AttackButton::attack(Entity *target, Entity *user) {
        auto damage = randomiseDamage(getBaseDamage(user, target));
        //damage calc
        target->updateHp("subtract", damage);
        printf("Did %f damage to entity\n", damage);
    }

    float AttackButton::getBaseDamage(Entity* player, Entity* target) {
        float baseDamage = Utilities::randf(10, 25);
        baseDamage *= 2;

        float damage = std::floor(baseDamage / 5);
        damage += 2;
        damage *= *player->getAttack();
        damage = std::floor(damage / *target->getDefense());
        damage = std::floor(damage / 50);

        if (damage > 997) damage = 997;

        damage += 2;

        return std::floor(damage * 50 / 50);
    }

    float AttackButton::randomiseDamage(float damage) {
        if (damage == 1) return 1;

        damage *= Utilities::randf(217, 255);
        return std::floor(damage / 255);
    }
}