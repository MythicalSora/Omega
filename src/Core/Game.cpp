#include <SFML/Window/Event.hpp>
#include <Core/Game.hpp>

namespace Core {
    Game::Game(int width, int height, std::string title, bool vsync, sf::RenderWindow** outWindow) {
        this->title = std::move(title);

        window.create(sf::VideoMode(width, height), this->title);
        window.setVerticalSyncEnabled(vsync);

        *outWindow = &window;

        scenes = std::vector<Scene*>();
        activeScene = nullptr;
    }

    void Game::run() {
        while (window.isOpen()) {
            // Event Handler
            sf::Event event { };
            while(window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) window.close();
            }

            window.clear();
            activeScene->update();
            window.display();
        }
    }

    void Game::addScene(Scene* scene) {
        scenes.push_back(scene);
    }

    void Game::setActiveScene(Scene* scene) {
        this->activeScene = scene;
        activeScene->init();
    }
}