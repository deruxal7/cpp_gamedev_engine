#include "Renderer.h"
#include <iostream>

Renderer::Renderer(SDL_Window* window) 
    : window(window) {
        context = SDL_GL_CreateContext(window);
        if (!context) {
            std::cerr << "OpenGL context could not be created: " << SDL_GetError() << std::endl;
            exit(-1);
        }

        if (glewInit() != GLEW_OK) {
            std::cerr << "Glew initialization failed!" << std::endl;
            exit(-1);
        }

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

Renderer::~Renderer() {
    SDL_GL_DeleteContext(context);
}

void Renderer::Clear() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::Draw() {
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.5f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.5f, -0.5f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.0f, 0.5f);
    glEnd();
}

void Renderer::Present() {
    SDL_GL_SwapWindow(window);
}