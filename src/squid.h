#ifndef SQUID_H
#define SQUID_H

#include "alien.h"
#include "string"

class Squid : public Alien {
public:
    const std::string kCharacterDirectory{"../characters/"};
    const std::string kSquidDirectory{"squid"};

    //Constructor & Destructor
    Squid(double init_x, double init_y);
    ~Squid() {}

    //typical behaviour methods
    void Simulate();
    void RunSquid();
};

#endif