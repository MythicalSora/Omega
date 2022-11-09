#include <SFML/Graphics.hpp>

#include <Core/Scene.hpp>
#include "Core/Game.hpp"
#include "Core/Sprite.hpp"

int main() {
    sf::RenderWindow* window;
    Core::Game game = Core::Game(3840, 2160, "Project: Omega - v0.1", true, &window);

    Core::Scene scene = Core::Scene(Utilities::SceneType::MENU, window);
    Core::Scene scene2 = Core::Scene(Utilities::SceneType::BATTLE, window);
    Core::Sprite sprite = Core::Sprite(sf::Vector2f(50, 50), sf::Vector2f(4, 4), sf::Color::Transparent, "assets/head.png");
    Core::Sprite sprite2 = Core::Sprite(sf::Vector2f(50, 50), sf::Vector2f(4, 4), sf::Color::Transparent, "assets/head_hurt.png");

    scene.addGameObject(&sprite);
    scene2.addGameObject(&sprite2);

    scene.addMusic("assets/Abstraction - Three Red Hearts - Puzzle Pieces.wav");
    scene2.addMusic("assets/Abstraction - Three Red Hearts - Pixel War 2.wav");

    scene.addSfxBuffer("assets/swordMetal7.ogg", "sword");
    scene2.addSfxBuffer("assets/swordMetal7.ogg", "sword");

    if (Utilities::IsType<Core::Sprite>(&sprite)) printf("You fucking did it you crazy cunt");

    game.addScene(&scene, scene.id);
    game.addScene(&scene2, scene2.id);

    game.setActiveScene(Utilities::SceneType::MENU);

    game.run();

    return 0;
}





