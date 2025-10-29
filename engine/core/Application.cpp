#include <iostream>
#include <glm/glm.hpp>
#include <cmath>
#include <memory>
#include <chrono>

#include "Application.h"
#include "Window.h"

namespace CacTus::Core {

Application::Application() 
    : m_window(std::make_unique<Window>("CacTus Engine - Rouguevival", 1024, 800)),
      m_renderer(m_window->getWindow())
{
    m_inputManager = std::make_unique<InputManager>();

    m_window->setInputCallback([this](const SDL_Event& event) {
        m_inputManager->processInput(event);
    });

    Entity player(100.0f, 500.0f, 50.0f, 50.0f, 1.0f);
    m_entityManager.addEntity(player);
}

Application::~Application() {
}

void Application::run() {
    auto lastTime = std::chrono::high_resolution_clock::now();
    while (m_window->isOpen()) {
        auto currentTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> deltaTime = currentTime - lastTime;
        lastTime = currentTime;
        m_window->pollEvents();

        Entity& player = getPlayer();
        player.setVelocity(glm::vec2(0.0f, 0.0f));

        glm::vec2 velocity(0.0f, 0.0f);
        float speed = player.getMaxSpeed();

        if (getInputManager().keyStates[SDLK_a]) {
            velocity.x -= speed * deltaTime.count();
        }
        if (getInputManager().keyStates[SDLK_d]) {
            velocity.x += speed * deltaTime.count();
        }
        if (getInputManager().keyStates[SDLK_w]) {
            velocity.y -= speed * deltaTime.count();
        }
        if (getInputManager().keyStates[SDLK_s]) {
            velocity.y += speed * deltaTime.count();
        }

        if (velocity.x != 0.0f || velocity.y != 0.0f) {
            velocity = glm::normalize(velocity) * speed;
        }
        

        player.setX(player.getX() + velocity.x); 
        player.setY(player.getY() + velocity.y);

        m_renderer.clear();

        for (const auto& entity : m_entityManager.getEntities()) {
            m_renderer.drawRect(entity.getX(), entity.getY(), entity.getWidth(), entity.getHeight());
        }

        m_renderer.present();
    }
}

InputManager& Application::getInputManager() {
    return *m_inputManager;
}

Entity& Application::getPlayer() {
    return m_entityManager.getEntity(0);
}

}