#include "squid.h"

Squid::Squid(double init_x, double init_y) {
    _alienType = AlienType::Squid;
    setPosition(init_x, init_y);
    bodySetup(kCharacterDirectory + kSquidDirectory);
}

void Squid::Simulate() {
    _threads.emplace_back(&Squid::RunSquid, this);
}