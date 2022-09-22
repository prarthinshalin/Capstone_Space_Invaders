#include "global_offensive.h"

GlobalOffensive::GlobalOffensive() {
    //Creating the aliens
    createAlien<Octopus>(START_Y_OCTOS, _octos);
    createAlien<Crab>(START_Y_CRABS, _crabs);
    createAlien<Squid>(START_Y_SQUIDS, _squids);

    //Since the GO starts out on the left, the only direction to go would be right
    _direction = Direction::kRight;

    //Starting the GO simulation
    Simulate();
}

template <class T>
void GlobalOffensive::createAlien(const double start_y, std::vector<std::unique_ptr<T>> &alienVector) {
    //Initializing starting positions
    double x_placement = START_X;
    double y_placement = start_y;

    //Creating the aliens and assigning them to their respective alien vectors
    for(double y = 0; y < 2; y++) { //Controlling the placement in y direction
        for(double i = 0; i < 11; i++) { //controlling the placement in the x direction
            //Creating the alien first and pushing it to the back of the alienVector
            std::unique_ptr<T> alien = std::make_unique<T>(x_placement, y_placement);
            //TODO: Start the alien simulation in a new thread
            alienVector.emplace_back(std::move(alien));

            //Increamenting x_placement;
            x_placement += SPACING_X;
        }

        //Resetting the x_placement
        x_placement = START_X;
        
        //Incrementing the y_placment
        y_placement += SPACING_Y;
    }
}

void GlobalOffensive::Simulate() {
    //Creating a seperate thread for the GO to run
    _thread = std::thread(&GlobalOffensive::Run, this);
}

void GlobalOffensive::Run() {
    Uint32 frameBegin, frameEnd, frameDuration;

    while(_running) {

        frameBegin = SDL_GetTicks();
    
        //Determining the direction of travel first
        if(_direction == Direction::kRight && (x + SIZE_X) >= LIMIT_X) {
            
            _direction = Direction::kLeft;

            //Shifting vertical position
            updateYPositions<Octopus>(_octos);
            updateYPositions<Crab>(_crabs);
            updateYPositions<Squid>(_squids);

        } else if(_direction == Direction::kLeft && x <= 0) {

            _direction = Direction::kRight;

            //Shifting vertical position
            updateYPositions<Octopus>(_octos);
            updateYPositions<Crab>(_crabs);
            updateYPositions<Squid>(_squids);
        }

        updateXPositions<Octopus>(_octos);
        updateXPositions<Crab>(_crabs);
        updateXPositions<Squid>(_squids);

        updateGOPosition();

        frameEnd = SDL_GetTicks();

        frameDuration = frameEnd - frameBegin;

        if(frameDuration < kMsPerFrame) {
            SDL_Delay(kMsPerFrame - frameDuration);
        }
    }
}

template <class T>
void GlobalOffensive::updateXPositions(std::vector<std::unique_ptr<T>> &alienVector) {
    //Update the alien
    for(auto &alien : alienVector) {
        if(_direction == Direction::kRight) {
            alien->shiftHorizontal(STEP_X);
            
        } else if(_direction == Direction::kLeft) {
            alien->shiftHorizontal(-1*STEP_X);
        }
    }
}

template <class T>
void GlobalOffensive::updateYPositions(std::vector<std::unique_ptr<T>> &alienVector) {
    for(auto &alien : alienVector) {
        alien->shiftVertical(STEP_Y);
    }
}

void GlobalOffensive::updateGOPosition() {
    //Update the GO position
    if(_direction == Direction::kRight) {
        x += STEP_X;
    } else if(_direction == Direction::kLeft) {
        x -= STEP_X;
    }
}

//Only defined for debugging purposes
void GlobalOffensive::RunSingle() {
    Uint32 frameStart, frameEnd, frameDuration;

    while(_running) {

        frameStart = SDL_GetTicks();

        for(auto &octo : _octos) {
            octo->shiftHorizontal(STEP_X);
        }

        frameEnd = SDL_GetTicks();

        frameDuration = frameEnd - frameStart;

        if(frameDuration < kMsPerFrame) {
            SDL_Delay(kMsPerFrame - frameDuration);
        }
    }
}