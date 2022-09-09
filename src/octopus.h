#ifndef OCTOPUS_H
#define OCTOPUS_H

#include "alien.h"

class Octopus : public Alien {
public:
    const std::string kCharacterDirectory{"../characters/"};
    const std::string kOctopusFile{"octopus"};

    Octopus(double init_x, double init_y);
};

#endif