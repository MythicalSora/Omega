#pragma once

#include "GameObject.hpp"

namespace Utilities {
    enum SceneType {
        MENU,
        BATTLE,
        HIGHSCORE,
        END
    };

    template<typename T>
    static bool IsType(Core::GameObject* object) {
        return dynamic_cast<T*>(object) != nullptr;
    }
}
