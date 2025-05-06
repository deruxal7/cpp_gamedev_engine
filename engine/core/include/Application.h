#pragma once

#include <memory>
#include <functional>

#include <SDL2/SDL.h>

#include "Window.h"
#include "Renderer.h"
#include "EntityManager.h"
#include "InputManager.h"
#include "Entity.h"

namespace CacTus::Core {

class Application {

public: 
    Application();
    ~Application();

    void run();
    Entity& getPlayer();
    InputManager& getInputManager();

private:
    std::unique_ptr<Window> m_window;
    Graphics::Renderer m_renderer;
    EntityManager m_entityManager;
    std::unique_ptr<InputManager> m_inputManager;
};

}