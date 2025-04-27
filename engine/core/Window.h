#pragma once

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>

namespace CacTus::Core {

class Window {

public:

    Window(const std::string& title, int width, int height);
    ~Window();

    bool isOpen() const;
    void pollEvents();
    void swapBuffers();
    SDL_Window* getWindow() const;

private:
    
    SDL_Window* m_window = nullptr;
    SDL_GLContext m_glContext = nullptr;
    bool m_isOpen = true;
};

}