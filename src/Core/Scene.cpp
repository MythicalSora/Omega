#include <cstdio>
#include <Core/Scene.hpp>

namespace Core {
    Scene::Scene(Utilities::SceneType id, sf::RenderWindow* window) {
        printf("Scene [%d] created\n", id);
        this->window = window;
        this->id = id;
        this->gameObjects = std::vector<GameObject*>();
        this->sfxBuffers = std::map<std::string, sf::SoundBuffer>();
    }

    void Scene::addGameObject(GameObject* object) {
        this->gameObjects.push_back(object);
    }

    void Scene::addGameObjects(std::vector<GameObject *> objects) {
        for (GameObject* object : objects) {
            addGameObject(object);
        }
    }

    void Scene::addSfxBuffer(std::string fileName, std::string id) {
        sf::SoundBuffer buffer;
        if (!buffer.loadFromFile(fileName)) throw std::runtime_error("Could not load sfx");
        this->sfxBuffers.emplace(id, buffer);
    }

    void Scene::addSfxBuffers(std::map<std::string, sf::SoundBuffer> buffers) {
        this->sfxBuffers.insert(buffers.begin(), buffers.end());
    }

    void Scene::addMusic(std::string fileName) {
        if (!this->music.openFromFile(fileName)) throw std::runtime_error("Could not load music");
    }

    void Scene::playMusic() {
        this->music.play();
        this->music.setLoop(true);
    }

    void Scene::playSfx(std::string id) {
        this->sfx.setBuffer(this->sfxBuffers.find(id)->second);
        this->sfx.play();
    }

    void Scene::unload() {
        if(this->music.Playing) this->music.stop();
    }

    void Scene::init() {
        printf("Activating scene [%d]\n", id);
        playMusic();
    }

    void Scene::update() {
        renderGameObjects();
    }

    void Scene::renderGameObjects() {
        for (GameObject* gameObject : gameObjects) {
            window->draw(*gameObject->getDrawable());
            gameObject->update();
        }
    }
}