#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <Core/GameObject.hpp>

namespace Core {
    class Scene {
        protected:
            sf::RenderWindow* window;
            std::vector<GameObject*> gameObjects;
        
        private:
            std::string id;
        
        private:
            void renderGameObjects();
        
        protected:
            explicit Scene(sf::RenderWindow* window, std::string id);
        
        public:
            virtual void init();
            virtual void update();
    };
}