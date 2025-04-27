#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <SDL2/SDL.h>

class Renderer {
public:
    Renderer(SDL_Window* window);
    ~Renderer();

    void Clear();
    void Draw();
    void Present();

private:
    SDL_Window* window;
    SDL_GLContext context;
};
#endif