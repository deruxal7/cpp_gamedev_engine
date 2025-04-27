#pragma once

#include <GL/glew.h>
#include <SDL2/SDL.h>

namespace CacTus::Graphics {

class Renderer {
public:
    Renderer(SDL_Window* window);

    void clear();
    void drawRect(float x, float y, float width, float height);
    void present();

private:
    SDL_Window* m_window;
};
}