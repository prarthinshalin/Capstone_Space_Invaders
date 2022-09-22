#include "controller.h"

void Controller::HandleInput(bool &running, Spaceship &spaceship) {
    SDL_Event e;
    while(SDL_PollEvent(&e)) {
        if(e.type == SDL_QUIT) {
            running = false;
        } else if(e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym)
            {
            case SDLK_LEFT:
                spaceship.MoveLeft();
                break;

            case SDLK_RIGHT: 
                spaceship.MoveRight();
                break;

            case SDLK_SPACE:
                spaceship.FireBullet();
                break;
            }
        }
    }
}