#pragma once

#include <map>
#include <Core/Scene.hpp>
#include <SFML/Audio.hpp>
#include "Utilities.hpp"

namespace Core {
    class Game {
        private:
            std::string title;
            sf::RenderWindow window;
            std::map<Utilities::SceneType, Scene*> scenes;
            Scene* activeScene;
            Scene* nextActiveScene;
        
        public:
            Game(int width, int height, std::string title, bool vsync, sf::RenderWindow** outWindow);
            void run();
            void addScene(Scene* scene, Utilities::SceneType type);
            void setActiveScene(Utilities::SceneType type);
    };
}