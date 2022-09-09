#include "crab.h"

Crab::Crab(double init_x, double init_y) {
    setPosition(init_x, init_y);
    bodySetup(kCharacterDirectory + kCrabDirectory);
}