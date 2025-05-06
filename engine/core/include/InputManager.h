#pragma once

#include <map>

#include <SDL2/SDL.h>

#include "Entity.h"

namespace CacTus::Core {

class InputManager {
public:
    InputManager();
    ~InputManager() = default;

    void processInput(const SDL_Event& event);
    std::map<SDL_Keycode, bool> keyStates;
};

}