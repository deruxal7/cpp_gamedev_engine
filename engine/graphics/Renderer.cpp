#include "Renderer.h"
#include <iostream>

namespace CacTus::Graphics {

Renderer::Renderer(SDL_Window* window) {
    m_window = window;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, 800.0f, 600.0f, 0.0f, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
}

void Renderer::clear() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::drawRect(float x, float y, float width, float height) {
    glColor3f(0.0f, 1.0f, 0.0f);

    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width, y + height);
        glVertex2f(x, y + height);
    glEnd();

    glFlush();
}

void Renderer::present() {
    SDL_GL_SwapWindow(m_window);
}
}