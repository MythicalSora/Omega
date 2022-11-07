#pragma once

#include <vector>
#include <Core/Scene.hpp>

namespace Core {
    class Game {
        private:
            std::string title;
            sf::RenderWindow window;
            std::vector<Scene*> scenes;
            Scene* activeScene;
        
        public:
            Game(int width, int height, std::string title, bool vsync, sf::RenderWindow** outWindow);
            void run();
            void addScene(Scene* scene);
            void setActiveScene(Scene* scene);
    };
}