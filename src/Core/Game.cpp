#include <SFML/Window/Event.hpp>
#include <Core/Game.hpp>
#include "Buttons/SceneButton.hpp"
#include "Buttons/AttackButton.hpp"
#include "Buttons/HealButton.hpp"

namespace Core {
    Game::Game(int width, int height, std::string title, bool vsync, sf::RenderWindow** outWindow) {
        this->title = std::move(title);

        window.create(sf::VideoMode(width, height), this->title);
        window.setVerticalSyncEnabled(vsync);

        *outWindow = &window;

        scenes = std::map<Utilities::SceneType, Scene*>();
        activeScene = nullptr;
        nextActiveScene = nullptr;
    }

    void Game::run() {
        while (window.isOpen()) {
            // Event Handler
            sf::Event event { };
            while(window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) window.close();

                if(event.type == sf::Event::KeyReleased) {
                    if(event.key.code == sf::Keyboard::A) {
                        if (activeScene->id == Utilities::SceneType::MENU)
                            setActiveScene(Utilities::SceneType::BATTLE);
                        else
                            setActiveScene(Utilities::SceneType::MENU);
                    }

                    if(event.key.code == sf::Keyboard::Up) {
                        activeScene->playSfx("sword");
                    }
                }
            }

            window.clear();

            if (nextActiveScene) {
                activeScene = nextActiveScene;
                activeScene->init();
                nextActiveScene = nullptr;
            }

            activeScene->update();

            for (GameObject* object : activeScene->gameObjects) {
                if (Utilities::IsType<Buttons::SceneButton>(object)) {
                    auto* button = dynamic_cast<Buttons::SceneButton*>(object);
                    if (button->isClicked()) {
                        setActiveScene(button->scene);
                    }
                } else if (Utilities::IsType<Buttons::AttackButton>(object)) {
                    auto* button = dynamic_cast<Buttons::AttackButton*>(object);
                    if (button->isClicked()) {
                        button->attack((Entity*)activeScene->gameObjects[2], (Entity*)activeScene->gameObjects[3]);
                    }
                } else if (Utilities::IsType<Buttons::HealButton>(object)) {
                auto* button = dynamic_cast<Buttons::HealButton*>(object);
                if (button->isClicked()) {
                    button->heal((Entity*)activeScene->gameObjects[2]);
                }
            }
            }

            window.display();
        }
    }

    void Game::addScene(Scene* scene, Utilities::SceneType type) {
        scenes.emplace(type, scene);
    }

    void Game::setActiveScene(Utilities::SceneType type) {
        if (scenes.contains(type)) {
            nextActiveScene = scenes.at(type);
            if (activeScene != nullptr) activeScene->unload();
        }

        else
            printf("Scene [%d] not loaded", type);
    }
}