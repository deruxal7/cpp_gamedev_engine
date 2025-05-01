#include "Window.h"
#include "Renderer.h"
#include "EntityManager.h"
#include "InputManager.h"

#include <iostream>
#include <memory>
#include <functional>

using namespace CacTus::Core;
using namespace CacTus::Graphics;

int main(int argc, char* argv[]) {
    std::unique_ptr<Window> window = std::make_unique<Window>("CacTus Engine - TopDownGame", 800, 600);
    Renderer renderer(window->getWindow());

    EntityManager entityManager;

    std::unique_ptr<InputManager> inputManager = std::make_unique<InputManager>();

    window->setInputCallback([&](const SDL_Event& event) {
        inputManager->processInput(event);
    });

    std::unique_ptr<MoveDownAction> moveDownAction = std::make_unique<MoveDownAction>();
    std::unique_ptr<MoveUpAction> moveUpAction = std::make_unique<MoveUpAction>();
    std::unique_ptr<MoveLeftAction> moveLeftAction = std::make_unique<MoveLeftAction>();
    std::unique_ptr<MoveRightAction> moveRightAction = std::make_unique<MoveRightAction>();

    inputManager->bindKey(SDLK_a, moveLeftAction.get());
    inputManager->bindKey(SDLK_d, moveRightAction.get());
    inputManager->bindKey(SDLK_w, moveUpAction.get());
    inputManager->bindKey(SDLK_s, moveDownAction.get());

    Entity player(100.0f, 500.0f, 50.0f, 50.0f);
    entityManager.addEntity(player);

    bool isRunning = true;

    while (isRunning) {
        window->pollEvents();

        if (!window->isOpen()) {
            isRunning = false;
        }
        renderer.clear();

        for (const auto& entity : entityManager.getEntities()) {
            renderer.drawRect(entity.getX(), entity.getY(), entity.getWidth(), entity.getHeight());
        }

        renderer.present();
    }

    return 0;
}