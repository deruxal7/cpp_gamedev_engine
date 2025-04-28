#include "Renderer.h"
#include <GL/glew.h>
#include <iostream>

namespace CacTus::Graphics {


Renderer::Renderer(SDL_Window* window) 
    : m_window(window)
{
    m_shader = new Shader("shaders/vertex.glsl", "shaders/fragment.glsl");
}

Renderer::~Renderer() {
    delete m_shader;
    glDeleteVertexArrays(1, &m_VAO);
    glDeleteBuffers(1, &m_VBO);
}

void Renderer::clear() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::drawRect(float x, float y, float width, float height) {
    m_shader->bind();

    float vertices[] = {
        x, y,
        x+width, y,
        x+width, y+height,
        x, y+height
    };

    unsigned int VBO, VAO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glDrawArrays(GL_QUADS, 0, 4);

    m_shader->unbind();

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Renderer::present() {
    SDL_GL_SwapWindow(m_window);
}

}