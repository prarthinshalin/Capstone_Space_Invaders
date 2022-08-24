#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include "spaceship.h"
#include "bullet.h"

class Renderer {
public:

    //Constructor and Destructor
    Renderer(const std::size_t screen_width, const std::size_t screen_height, const std::size_t grid_width, const std::size_t grid_height);
    ~Renderer();

    void Render(Spaceship const spaceship, std::vector<std::shared_ptr<Bullet>> const &bullets);
    void updateWindowTitle();

private:
    SDL_Window *_window;
    SDL_Renderer *_renderer;

    const std::size_t _screen_width;
    const std::size_t _screen_height;
    const std::size_t _grid_width;
    const std::size_t _grid_height;
};

#endif