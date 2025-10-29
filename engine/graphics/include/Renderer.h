#pragma once

#include "Shader.h"
#include <memory>
#include <SDL2/SDL.h>
#include <vector>

namespace CacTus::Graphics {

class Renderer {
public:
    Renderer(SDL_Window* window, size_t initialSize = 1024 * sizeof(float));
    ~Renderer();

    void clear();
    void drawRect(float x, float y, float width, float height);
    void present();

private:
    SDL_Window* m_window;
    std::unique_ptr<Shader> m_shader;

    unsigned int m_VAO, m_VBO, m_EBO;
    int m_screenWidth, m_screenHeight;
    std::vector<float> m_vertices;
    std::vector<unsigned int> m_indices;
};
}