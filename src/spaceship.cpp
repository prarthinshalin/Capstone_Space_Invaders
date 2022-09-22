#include "spaceship.h"

Spaceship::Spaceship(int start_x, int start_y) : pos_x(start_x - 5), pos_y(start_y - 4) {
    bitToPoints();
    std::cout << "This is working!\n";
    simulate();
}

void Spaceship::simulate() {
    std::cout << "This is working!\n";
    threads.emplace_back(std::thread(&Spaceship::FireUpSpaceship, this));
}

void Spaceship::FireUpSpaceship() {
    //Implement an infinite loop that will check whether any bullets have reached the end
        std::cout << "This is working!\n";
    while(true) {
            std::cout << "This is working!\n";
        //Sleeping during each iteration to redure CPU usage
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

        //No need to monitor all the bullets, just the first one
        if((_bullets.front())->pos_y <= 0) {
            _bullets.pop_front();
        }
    }
}

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

void Spaceship::FireBullet() {
    std::shared_ptr<Bullet> newBullet = std::make_shared<Bullet>(pos_x, pos_y);
    newBullet->simulate();
    _bullets.emplace_back(std::move(newBullet));
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