#include <iostream>
#include "renderer.h"
#include "controller.h"
#include <thread>

#define SPACESHIP_START_POS_X 160
#define SPACESHIP_START_POS_Y 210

int main() {
    std::cout << "Hello World!" << "\n";
    constexpr std::size_t kFramesPerSeconds{60};
    constexpr std::size_t kMsPerFrame{1000 / kFramesPerSeconds};
    bool running{true};
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 frame_duration;

    Renderer renderer(640, 480, 320, 240);
    Spaceship spaceship(SPACESHIP_START_POS_X, SPACESHIP_START_POS_Y);
    std::vector<std::shared_ptr<Bullet>> bullets;
    Controller controller;
    
    while(running) {
        frame_start = SDL_GetTicks();

        controller.HandleInput(running, spaceship, bullets);
        renderer.Render(spaceship, bullets);

        frame_end = SDL_GetTicks();

        frame_duration = frame_end - frame_start;

        if(frame_duration < kMsPerFrame) {
            SDL_Delay(kMsPerFrame - frame_duration);
        }

    }

    return 0;
}