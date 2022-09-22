#include <iostream>
#include "renderer.h"
#include "controller.h"
#include "global_offensive.h"

#define SPACESHIP_START_POS_X 160
#define SPACESHIP_START_POS_Y 210

int main() {
    std::cout << "Hello World!" << "\n";
    constexpr std::size_t kFramesPerSeconds{60};
    constexpr std::size_t kMsPerFrame{1000 / kFramesPerSeconds};
    const double grid_width{320};
    const double grid_height{240};
    bool running{true};
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 frame_duration;

    Renderer renderer(640, 480, 320, 240);
    std::cout << "This is working!\n";
    Spaceship spaceship(SPACESHIP_START_POS_X, SPACESHIP_START_POS_Y);
    Controller controller;
    GlobalOffensive go;

    std::cout << "This is working!\n";

    while(running) {
        frame_start = SDL_GetTicks();

        controller.HandleInput(running, spaceship);
        renderer.Render(spaceship, go);

        frame_end = SDL_GetTicks();

        frame_duration = frame_end - frame_start;

        if(frame_duration < kMsPerFrame) {
            SDL_Delay(kMsPerFrame - frame_duration);
        }

    }

    return 0;
}