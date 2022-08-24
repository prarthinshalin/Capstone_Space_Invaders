#include "controller.h"

void Controller::HandleInput(bool &running, Spaceship &spaceship, std::vector<std::shared_ptr<Bullet>> &bullets) {
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
                std::shared_ptr<Bullet> newBullet = std::make_shared<Bullet>(spaceship.pos_x, BULLETS_STARTING_POS);
                bullets.emplace_back(std::move(newBullet));
                break;
            }
        }
    }
}