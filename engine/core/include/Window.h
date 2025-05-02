#pragma once

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>
#include <functional>

#include "InputManager.h"

namespace CacTus::Core {

class Window {

public:

    Window(const std::string& title, int width, int height);
    ~Window();

    bool isOpen() const;
    void setInputCallback(std::function<void(const SDL_Event&)> callback);
    void pollEvents();
    void swapBuffers();
    SDL_Window* getWindow() const;

private:
    
    SDL_Window* m_window = nullptr;
    SDL_GLContext m_glContext = nullptr;
    bool m_isOpen = true;
    std::function<void(const SDL_Event&)> m_inputCallback;
};


}