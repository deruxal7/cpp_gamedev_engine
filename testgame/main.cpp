#include "Window.h"
#include "Renderer.h"
#include "EntityManager.h"

#include <iostream>
#include <memory>

using namespace CacTus::Core;
using namespace CacTus::Graphics;

int main(int argc, char* argv[]) {
    Window window("CacTus Engine - TopDownGame", 800, 600);
    Renderer renderer(window.getWindow());

    EntityManager entityManager;

    Entity player(100.0f, 500.0f, 50.0f, 50.0f);
    entityManager.addEntity(player);

    bool isRunning = true;

    while (isRunning) {
        window.pollEvents();

        if (!window.isOpen()) {
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