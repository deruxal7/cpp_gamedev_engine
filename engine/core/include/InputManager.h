#pragma once

#include <map>
#include <SDL2/SDL.h>
#include "InputActions.h"
#include "Entity.h"

namespace CacTus::Core {

class InputManager {

public:
    InputManager();
    ~InputManager() = default;

    void bindKey(SDL_Keycode key, InputActions* action);
    void processInput(const SDL_Event& event);
    std::map<SDL_Keycode, bool> keyStates;

private:
    std::map<SDL_Keycode, InputActions*> m_keyBinds;

};

}