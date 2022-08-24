#ifndef SPACESHIP_H
#define SPACESHIP_H

#define SPACESHIP_WIDTH 11;
#define SPACESHIP_HEIGHT 8;

#include <SDL2/SDL.h>
#include <vector>

class Spaceship {
public:

    //Constructor and Destructor
    Spaceship(int start_x, int start_y);
    ~Spaceship();

    void MoveLeft();
    void MoveRight();

    std::vector<SDL_Point> body;
    int pos_x;
    int pos_y;

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