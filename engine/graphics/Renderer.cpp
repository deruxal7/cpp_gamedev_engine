#include "Renderer.h"
#include <GL/glew.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace CacTus::Graphics {

Renderer::Renderer(SDL_Window* window)
    : m_window(window)
{
    SDL_GetWindowSize(m_window, &m_screenWidth, &m_screenHeight);

    m_shader = new Shader("engine/graphics/shaders/vertex.glsl", "engine/graphics/shaders/fragment.glsl");

    // Создаем VAO и VBO один раз
    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);
    glBindVertexArray(m_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

    // Настраиваем атрибуты вершин один раз
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Создаем и передаем матрицу проекции
    glm::mat4 projection = glm::ortho(0.0f, (float)m_screenWidth, (float)m_screenHeight, 0.0f, -1.0f, 1.0f);
    m_shader->bind();
    m_shader->setUniformMatrix4fv("u_Projection", projection);
    m_shader->setUniform4f("u_Color", 0.0f, 1.0f, 0.3f, 1.0f);
    m_shader->unbind();

    glBindBuffer(GL_ARRAY_BUFFER, 0); // Отвязываем VBO
    glBindVertexArray(0); // Отвязываем VAO
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
        x + width, y,
        x + width, y + height,
        x, y + height
    };

    glBindVertexArray(m_VAO); // Привязываем VAO

    glBindBuffer(GL_ARRAY_BUFFER, m_VBO); // Привязываем VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // Обновляем данные вершин

    glDrawArrays(GL_TRIANGLE_FAN, 0, 4); // Рисуем

    glBindBuffer(GL_ARRAY_BUFFER, 0); // Отвязываем VBO
    glBindVertexArray(0); // Отвязываем VAO

    m_shader->unbind();
}

void Renderer::present() {
    SDL_GL_SwapWindow(m_window);
}

}