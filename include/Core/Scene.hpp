#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <Core/GameObject.hpp>
#include <map>
#include "Utilities.hpp"
#include "SFML/Audio.hpp"

namespace Core {
    class Scene {
    protected:
        sf::RenderWindow* window;
        sf::Music music;
        sf::Sound sfx;
        std::map<std::string, sf::SoundBuffer> sfxBuffers;
        std::vector<GameObject*> gameObjects;

    public:
        Utilities::SceneType id;

    private:
        void renderGameObjects();

    public:
        void addGameObject(GameObject* object);
        void addGameObjects(std::vector<GameObject*> objects);
        void addSfxBuffer(std::string fileName, std::string id);
        void addSfxBuffers(std::map<std::string, sf::SoundBuffer> buffers);
        void addMusic(std::string fileName);

        void playMusic();
        void playSfx(std::string id);

        void unload();

        virtual void init();
        virtual void update();

        explicit Scene(Utilities::SceneType id, sf::RenderWindow* window);
    };
}