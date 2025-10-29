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

    Entity player(100.0f, 500.0f, 50.0f, 50.0f, 500.0f);
    m_entityManager.addEntity(player);
}

Application::~Application() {
}

void Application::run() {
    static int frames = 0;
    static float fpsTimer = 0.0f;
    auto lastTime = std::chrono::high_resolution_clock::now();
    while (m_window->isOpen()) {
        auto currentTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> deltaTime = currentTime - lastTime;
        float dt = std::min(deltaTime.count(), 0.1f);
        frames++; fpsTimer += dt;
        if (fpsTimer >= 1.0f) {
            std::cout << "[Info] FPS: " << frames / fpsTimer << std::endl;
            frames = 0;
            fpsTimer = 0.0f;
        }
        lastTime = currentTime;
        m_window->pollEvents();

        Entity& player = getPlayer();
        player.setVelocity(glm::vec2(0.0f, 0.0f));

        glm::vec2 direction(0.0f, 0.0f);
        float speed = player.getMaxSpeed();

        if (getInputManager().keyStates[SDLK_a]) {
            direction.x -= 1;
        }
        if (getInputManager().keyStates[SDLK_d]) {
            direction.x += 1;
        }
        if (getInputManager().keyStates[SDLK_w]) {
            direction.y -= 1;
        }
        if (getInputManager().keyStates[SDLK_s]) {
            direction.y += 1;
        }

        if (direction.x != 0.0f || direction.y != 0.0f) {
            direction = glm::normalize(direction) * speed * dt;
        }
        

        player.setX(player.getX() + direction.x); 
        player.setY(player.getY() + direction.y);

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