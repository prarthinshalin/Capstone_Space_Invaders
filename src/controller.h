#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "spaceship.h"
#include "bullet.h"
#include <thread>

#define BULLETS_STARTING_POS 206

class Controller {
public:
    void HandleInput(bool &running, Spaceship &shaceship, std::vector<std::shared_ptr<Bullet>> &bullets);

private:
};

#endif