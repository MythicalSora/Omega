#include <cstdio>
#include <Core/Scene.hpp>

namespace Core {
    Scene::Scene(sf::RenderWindow* window, std::string id) {
        printf("Scene [%s] created\n", id.c_str());
        this->window = window;
        this->id = std::move(id);
    }

    void Scene::init() {
        printf("Activating scene [%s]\n", this->id.c_str());
    }

    void Scene::update() {

    }

    void Scene::renderGameObjects() {
        for (GameObject* gameObject : gameObjects) {
            window->draw(*gameObject->getDrawable());
        }
    }
}