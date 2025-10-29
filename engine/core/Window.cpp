#include "Window.h"
#include <iostream>
#include <stdexcept>

namespace CacTus::Core {

Window::Window(const std::string& title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::string msg = std::string("[Error] SDL could not initialize! SDL_Error: ") + SDL_GetError();
        m_isOpen = false;
        throw std::runtime_error(msg);
    }

    std::cout << "[Info] SDL initialized successfully!" << std::endl;

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    m_window = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
    );

    if (!m_window) {
        std::string msg = std::string("[Error] Window could not be created! SDL_Error: ") + SDL_GetError();
        m_isOpen = false;
        throw std::runtime_error(msg);
    }
    std::cout << "[Info] Window created successfully!" << std::endl;

    m_glContext = SDL_GL_CreateContext(m_window);
    if(!m_glContext) {
        std::string msg = std::string("[Error] OpenGL context could not be created! SDL_Error: ") + SDL_GetError();
        m_isOpen = false;
        throw std::runtime_error(msg);
    }
    std::cout << "[Info] OpenGL context created successfully!" << std::endl;
    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK) {
        throw std::runtime_error("[Error] GLEW could not be initialized!");
    }
    std::cout << "[Info] GLEW initialized successfully!" << std::endl;

    SDL_GL_SetSwapInterval(1);
}

Window::~Window() {
    SDL_GL_DeleteContext(m_glContext);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

bool Window::isOpen() const{
    return m_isOpen;
}

void Window::setInputCallback(std::function<void(const SDL_Event&)> callback) {
    m_inputCallback = callback;
}

void Window::pollEvents() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                m_isOpen = false;
                break;
        }
        if(m_inputCallback) {
            m_inputCallback(event);
        }
    }
}

void Window::swapBuffers() {
    SDL_GL_SwapWindow(m_window);
}

SDL_Window* Window::getWindow() const{
    return m_window;
}
}