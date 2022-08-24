#include "bullet.h"
#include <thread>

void Bullet::Update() {
    pos_y -= 1;
}

void Bullet::simulate() {
    threads.emplace_back(std::thread(&Bullet::fire, this));
}

void Bullet::fire() {
    constexpr std::size_t kFramesPerSeconds{60};
    constexpr std::size_t kMsPerFrame{1000 / kFramesPerSeconds};
    bool inScope{true};
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 frame_duration;

    while(inScope) {
        frame_start = SDL_GetTicks();

        this->Update();

        frame_end = SDL_GetTicks();

        frame_duration = frame_end - frame_start;

        if(this->pos_y <= 0) { inScope = false; }

        if(frame_duration < kMsPerFrame) {
            SDL_Delay(kMsPerFrame - frame_duration);
        }
    }
}