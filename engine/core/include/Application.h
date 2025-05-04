#pragma once

#include <memory>
#include <functional>

#include <SDL2/SDL.h>

#include "Window.h"
#include "Renderer.h"
#include "EntityManager.h"
#include "InputManager.h"

namespace CacTus::Core {

class Application {

public: 
    Application();
    ~Application();

    void run();

private:
    std::unique_ptr<Window> m_window;
    Graphics::Renderer m_renderer;
    EntityManager m_entityManager;
    std::unique_ptr<InputManager> m_inputManager;
    std::unique_ptr<MoveDownAction> m_moveDownAction;
    std::unique_ptr<MoveUpAction> m_moveUpAction;
    std::unique_ptr<MoveLeftAction> m_moveLeftAction;
    std::unique_ptr<MoveRightAction> m_moveRightAction;

    void processInput(const SDL_Event& event);
};

}