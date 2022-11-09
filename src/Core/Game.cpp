#include <SFML/Window/Event.hpp>
#include <Core/Game.hpp>

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