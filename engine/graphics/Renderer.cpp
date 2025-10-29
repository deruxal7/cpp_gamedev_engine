#include "Renderer.h"
#include <GL/glew.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <memory>

namespace CacTus::Graphics {

Renderer::Renderer(SDL_Window* window, size_t initialSize)
    : m_window(window)
{
    SDL_GetWindowSize(m_window, &m_screenWidth, &m_screenHeight);

    m_shader = std::make_unique<Shader>("engine/graphics/shaders/vertex.glsl", "engine/graphics/shaders/fragment.glsl");

    // Create VAO VBO EBO
    glGenVertexArrays(1, &m_VAO);
    glGenBuffers(1, &m_VBO);
    glGenBuffers(1, &m_EBO);

    glBindVertexArray(m_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, initialSize, nullptr, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 0, nullptr, GL_DYNAMIC_DRAW);
    glBindVertexArray(0);

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
    m_shader.reset();
    glDeleteVertexArrays(1, &m_VAO);
    glDeleteBuffers(1, &m_VBO);
}

void Renderer::clear() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::drawRect(float x, float y, float width, float height) {
    unsigned int baseIndex = static_cast<unsigned int>(m_vertices.size() / 2);
    m_vertices.push_back(x); m_vertices.push_back(y);
    m_vertices.push_back(x + width); m_vertices.push_back(y);
    m_vertices.push_back(x + width); m_vertices.push_back(y + height);
    m_vertices.push_back(x); m_vertices.push_back(y + height);

    m_indices.push_back(baseIndex + 0);
    m_indices.push_back(baseIndex + 1);
    m_indices.push_back(baseIndex + 2);
    m_indices.push_back(baseIndex + 2);
    m_indices.push_back(baseIndex + 3);
    m_indices.push_back(baseIndex + 0);
}

void Renderer::present() {
    if (m_vertices.empty() || m_indices.empty()) {
        SDL_GL_SwapWindow(m_window);
        return;
    }
    
    m_shader->bind();
    glBindVertexArray(m_VAO);
    // VBO
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    size_t vertBytes = m_vertices.size() * sizeof(float);
    glBufferData(GL_ARRAY_BUFFER, vertBytes, m_vertices.data(), GL_DYNAMIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, vertBytes, m_vertices.data());
    // EBO
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    size_t indexBytes = m_indices.size() * sizeof(unsigned int);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexBytes, m_indices.data(), GL_DYNAMIC_DRAW);

    glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(m_indices.size()), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    m_shader->unbind();

    SDL_GL_SwapWindow(m_window);

    m_vertices.clear();
    m_indices.clear();
}

}