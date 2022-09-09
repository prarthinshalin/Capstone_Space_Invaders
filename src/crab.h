#ifndef CRAB_H
#define CRAB_H

#include "alien.h"
#include "string"

class Crab : public Alien {
public:
    const std::string kCharacterDirectory{"../characters/"};
    const std::string kCrabDirectory{"crab"};

    Crab(double init_x, double init_y);
};

#endif