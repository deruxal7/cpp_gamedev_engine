#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "Renderer.h"
#include <iostream>

int main(int argc, char* argv[]) {
    // Инициализация SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Создание окна
    SDL_Window* window = SDL_CreateWindow("CacTusEngine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_OPENGL);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Создание рендерера
    Renderer renderer(window);

    // Главный цикл игры
    bool isRunning = true;
    SDL_Event event;
    while (isRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isRunning = false;
            }
        }

        renderer.Clear();
        renderer.Draw();
        renderer.Present();
    }

    // Завершение работы
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
