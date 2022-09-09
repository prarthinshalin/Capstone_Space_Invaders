#include "renderer.h"
#include <string>
#include <iostream>

Renderer::Renderer(const std::size_t screen_width, const std::size_t screen_height, const std::size_t grid_width, const std::size_t grid_height)
                : _screen_width(screen_width),
                  _screen_height(screen_height),
                  _grid_width(grid_width),
                  _grid_height(grid_height) {
        
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }

    // Create Window
    _window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED, screen_width,
                                    screen_height, SDL_WINDOW_SHOWN);

    if (nullptr == _window) {
        std::cerr << "Window could not be created.\n";
        std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
    }

    // Create renderer
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if (nullptr == _renderer) {
        std::cerr << "Renderer could not be created.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }

}

Renderer::~Renderer() {
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void Renderer::Render(Spaceship const spaceship, std::vector<std::shared_ptr<Bullet>> const &bullets, GlobalOffensive const &go) {
    SDL_Rect block;
    block.w = _screen_width / _grid_width;
    block.h = _screen_height / _grid_height;

    //Clear screen
    SDL_SetRenderDrawColor(_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
    SDL_RenderClear(_renderer);

    //Rendering the body of the spaceship
    SDL_SetRenderDrawColor(_renderer, 0x00, 0xFF, 0x00, 0xFF);
    for(auto const &point : spaceship.body) {
        block.x = point.x * block.w;
        block.y = point.y * block.h;
        SDL_RenderFillRect(_renderer, &block);
    }

    //Rendering the bullets
    SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    for(auto const &bullet : bullets) {
        block.x = bullet->pos_x * block.w;
        block.y = bullet->pos_y * block.h;
        SDL_RenderFillRect(_renderer, &block);
    }

    //Rendering the global offensive
    SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    for(auto const &squid : go._squids) {
        for(auto const &squidpoint : squid->_body) {
            block.x = squidpoint.x * block.w;
            block.y = squidpoint.y * block.h;
            SDL_RenderFillRect(_renderer, &block);
        }
    }
    
    for(auto const &crab: go._crabs) {
        for(auto const &crabpoint : crab->_body) {
            block.x = crabpoint.x * block.w;
            block.y = crabpoint.y * block.h;
            SDL_RenderFillRect(_renderer, &block);
        }
    }

    for(auto const &octo: go._octos) {
        for(auto const &octopoint : octo->_body) {
            block.x = octopoint.x * block.w;
            block.y = octopoint.y * block.h;
            SDL_RenderFillRect(_renderer, &block);
        }
    }

    //Update Screen
    SDL_RenderPresent(_renderer);
}