#include "globaloffensive.h"

GlobalOffensive::GlobalOffensive(double grid_width, double grid_height) : _grid_width(grid_width), _grid_height(grid_height) {

    for(int i = 0; i < 2; i++) {

        //Creating the vector of squids
        START_X = 0;
        for(int j = 0; j < 11; j++) {
            std::unique_ptr<Squid> tempSquid = std::make_unique<Squid>(START_X, SQUID_START_Y);
            _squids.emplace_back(std::move(tempSquid));
            START_X += X_SPACING;
        }
        SQUID_START_Y += Y_SPACING;

        //Creating the vector of CRABS
        START_X = 0;
        for(int j = 0; j < 11; j++) {
            std::unique_ptr<Crab> tempCrab = std::make_unique<Crab>(START_X, CRAB_START_Y);
            _crabs.emplace_back(std::move(tempCrab));
            START_X += X_SPACING;
        }
        CRAB_START_Y += Y_SPACING;

        //Creating the vector of OCTOPUS
        START_X = 0;
        for(int j = 0; j < 11; j++) {
            std::unique_ptr<Octopus> tempOcto = std::make_unique<Octopus>(START_X, OCTOPUS_START_Y);
            _octos.emplace_back(std::move(tempOcto));
            START_X += X_SPACING;
        }
        OCTOPUS_START_Y += Y_SPACING;
    }
}

void GlobalOffensive::Update() {
    if((y + GO_HEIGHT) < GO_LIMIT) {
        //Determine the direction of movement
        if(x <= 0) {
            _direction = Direction::kRight;
        } else if((x + GO_WIDTH) >= _grid_width) {
            _direction = Direction::kLeft;
        }

        //Actual updating
        switch (_direction)
        {
        case Direction::kRight:
            /* code */
            break;
        
        default:
            break;
        }
    }
}