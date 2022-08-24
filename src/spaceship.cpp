#include "spaceship.h"

Spaceship::Spaceship(int start_x, int start_y) : pos_x(start_x - 5), pos_y(start_y - 4) {
    bitToPoints();
}

Spaceship::~Spaceship() {}

void Spaceship::MoveLeft() {
    for(auto &point : body) {
        point.x -= 1;
    }
    pos_x -= 1;
}

void Spaceship::MoveRight() {
    for(auto &point : body) {
        point.x += 1;
    }
    pos_x += 1;
}

void Spaceship::bitToPoints() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 11; j++) {
            if(_bitmap[i][j] == 1) {
                //Creating a new SDL_Point
                SDL_Point p;
                p.x = pos_x + j;
                p.y = pos_y + i;

                //Placing the new point at the back of the body
                body.emplace_back(p);
            }
        }
    }
}