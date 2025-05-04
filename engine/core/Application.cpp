#include <iostream>

#include "Application.h"

namespace CacTus::Core {

Application::Application() 
    : m_window(std::make_unique<Window>("CacTus Engine - Rouguevival", 800, 600)),
      m_renderer(m_window->getWindow())
{
    m_inputManager = std::make_unique<InputManager>();

    m_moveDownAction = std::make_unique<MoveDownAction>();
    m_moveUpAction = std::make_unique<MoveUpAction>();
    m_moveLeftAction = std::make_unique<MoveLeftAction>();
    m_moveRightAction = std::make_unique<MoveRightAction>();

    m_inputManager->bindKey(SDLK_a, m_moveLeftAction.get());
    m_inputManager->bindKey(SDLK_d, m_moveRightAction.get());
    m_inputManager->bindKey(SDLK_w, m_moveUpAction.get());
    m_inputManager->bindKey(SDLK_s, m_moveDownAction.get());

    m_window->setInputCallback([this](const SDL_Event& event) {
        processInput(event);
    });

    Entity player(100.0f, 500.0f, 50.0f, 50.0f);
    m_entityManager.addEntity(player);
}

Application::~Application() {
}

void Application::run() {
    while (m_window->isOpen()) {
        m_window->pollEvents();

        m_renderer.clear();

        for (const auto& entity : m_entityManager.getEntities()) {
            m_renderer.drawRect(entity.getX(), entity.getY(), entity.getWidth(), entity.getHeight());
        }

        m_renderer.present();
    }
}

void Application::processInput(const SDL_Event& event) {
    m_inputManager->processInput(event);
}

}