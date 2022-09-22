#ifndef BULLET_H
#define BULLET_H

#include <SDL2/SDL.h>
#include <vector>
#include <thread>
#include <iostream>

class Bullet {
public:
    //Constructor
    Bullet(int start_x, int start_y) : pos_x(start_x), pos_y(start_y){}
    void Update();
    void simulate();
    void fire();

    std::vector<std::thread> threads;
    bool active{true};
    int pos_x;
    int pos_y;
};

#endif