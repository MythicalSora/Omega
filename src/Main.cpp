#include <SFML/Graphics.hpp>

#include <Core/Scene.hpp>
#include "Core/Game.hpp"
#include "Core/Sprite.hpp"
#include "Button.hpp"
#include "Buttons/SceneButton.hpp"
#include "Buttons/AttackButton.hpp"
#include "Buttons/HealButton.hpp"

int main() {
    sf::RenderWindow* window;
    Core::Game game = Core::Game(1920, 1080, "Project: Omega - v0.1", true, &window);

    Core::Scene scene = Core::Scene(Utilities::SceneType::MENU, window);
    Core::Scene scene2 = Core::Scene(Utilities::SceneType::BATTLE, window);
//    Core::Sprite sprite = Core::Sprite(sf::Vector2f(50, 50), sf::Vector2f(4, 4), sf::Color::Transparent, "assets/head.png");
//    Core::Sprite sprite2 = Core::Sprite(sf::Vector2f(50, 50), sf::Vector2f(4, 4), sf::Color::Transparent, "assets/head_hurt.png");

    Buttons::SceneButton button = Buttons::SceneButton(Utilities::SceneType::BATTLE, window, sf::Vector2f(200, 200), sf::Vector2f(150, 100), sf::Color::White, sf::Color::Magenta, "Click Me!");
    Buttons::AttackButton button2 = Buttons::AttackButton(window, sf::Vector2f(200, 200), sf::Vector2f(150, 100), sf::Color::White, sf::Color::Magenta, "Click Me!");
    Buttons::HealButton button3 = Buttons::HealButton(window, sf::Vector2f(400, 200), sf::Vector2f(150, 100), sf::Color::White, sf::Color::Magenta, "Click Me!");

    Entity player = Entity(100, 20, 17, sf::Vector2f(500, 500), sf::Vector2f(3, 3), sf::Color::Transparent, "assets/head.png");
    Entity enemy = Entity(100, 20, 17, sf::Vector2f(1000, 500), sf::Vector2f(3, 3), sf::Color::Transparent, "assets/head_hurt.png");

    scene.addGameObject(&button);
    scene2.addGameObject(&button2);
    scene2.addGameObject(&button3);
    scene2.addGameObject(&player);
    scene2.addGameObject(&enemy);

    scene.addMusic("assets/Abstraction - Three Red Hearts - Puzzle Pieces.wav");
    scene2.addMusic("assets/Abstraction - Three Red Hearts - Pixel War 2.wav");

    scene.addSfxBuffer("assets/swordMetal7.ogg", "sword");
    scene2.addSfxBuffer("assets/swordMetal7.ogg", "sword");

//    if (Utilities::IsType<Core::Sprite>(&sprite)) printf("You fucking did it you crazy cunt");

    game.addScene(&scene, scene.id);
    game.addScene(&scene2, scene2.id);

    game.setActiveScene(Utilities::SceneType::MENU);

    game.run();

    return 0;
}





