#pragma once

#include "Shader.h"
#include <memory>
#include <SDL2/SDL.h>

namespace CacTus::Graphics {

class Renderer {
public:
    Renderer(SDL_Window* window);
    ~Renderer();

    void clear();
    void drawRect(float x, float y, float width, float height);
    void present();

private:
    SDL_Window* m_window;
    std::unique_ptr<Shader> m_shader;

    unsigned int m_VAO, m_VBO;
    int m_screenWidth, m_screenHeight; // Добавляем ширину и высоту экрана
};
}