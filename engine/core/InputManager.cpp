#include "InputManager.h"

namespace CacTus::Core {

InputManager::InputManager() {
    // Define relations
}

void InputManager::bindKey(SDL_Keycode key, InputActions* action) {
    m_keyBinds[key] = action;
}

void InputManager::processInput(const SDL_Event& event, Entity& entity) {
    if (event.type == SDL_KEYDOWN) {
        auto it = m_keyBinds.find(event.key.keysym.sym);
        if (it != m_keyBinds.end()) {
            it->second->execute(entity);
        }
    }
}

}