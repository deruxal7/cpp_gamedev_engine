#include "InputManager.h"

namespace CacTus::Core {

InputManager::InputManager() {
    // Define relations
}

void InputManager::bindKey(SDL_Keycode key, InputActions* action) {
    m_keyBinds[key] = action;
}

void InputManager::processInput(const SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        keyStates[event.key.keysym.sym] = true;
    } else if (event.type == SDL_KEYUP) {
        keyStates[event.key.keysym.sym] = false;
    }
}

}