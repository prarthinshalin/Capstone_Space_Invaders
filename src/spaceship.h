#ifndef SPACESHIP_H
#define SPACESHIP_H

#define SPACESHIP_WIDTH 11;
#define SPACESHIP_HEIGHT 8;

#include <SDL2/SDL.h>
#include <deque>
#include <chrono>
#include "bullet.h"
#include "MessageQueue.h"

class Spaceship {
public:

    //Constructor and Destructor
    Spaceship(int start_x, int start_y);

    //Typical Behaviour Functions
    void simulate();
    void FireUpSpaceship();
    void MoveLeft();
    void MoveRight();
    void FireBullet();

    std::vector<SDL_Point> body;
    int pos_x;
    int pos_y;
    std::deque<std::shared_ptr<Bullet>> _bullets;
    std::vector<std::thread> threads;

private:

    void bitToPoints();

    int _bitmap[8][11] = {{0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
                         {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
                         {0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
                         {0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0},
                         {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                         {1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
                         {1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
                         {0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0}};
};

#endif