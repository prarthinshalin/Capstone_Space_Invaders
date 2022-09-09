#ifndef GLOBALOFFENSIVE_H
#define GLOBALOFFENSIVE_H

#include <vector>
#include <memory>
#include "squid.h"
#include "crab.h"
#include "octopus.h"

class GlobalOffensive {
public:
    double START_X{0};
    double SQUID_START_Y{0};
    double CRAB_START_Y{40};
    double OCTOPUS_START_Y{80};
    const double X_SPACING{21};
    const double Y_SPACING{20};
    const double GO_WIDTH{300};
    const double GO_HEIGHT{100};
    const double GO_LIMIT{250};

    enum Direction {
        kLeft,
        kRight
    };

    //Constructor
    GlobalOffensive(double grid_width, double grid_height);

    //typical behvaiour methods
    void Update();

    std::vector<std::unique_ptr<Squid>> _squids;
    std::vector<std::unique_ptr<Crab>> _crabs;
    std::vector<std::unique_ptr<Octopus>> _octos;
    double x;
    double y;
    const double _grid_width;
    const double _grid_height;
    Direction _direction = Direction::kRight;
};

#endif