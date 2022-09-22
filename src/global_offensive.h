#ifndef GLOBAL_OFFENSIVE
#define GLOBAL_OFFENSIVE

#include <vector>
#include <SDL2/SDL.h>
#include "squid.h"
#include "crab.h"
#include "octopus.h"

enum Direction {
    kLeft,
    kRight
};

class GlobalOffensive {
public:

    //Constructor
    GlobalOffensive();

    //Typical Behaviour Fucntions
    void Simulate();
    void Run();

    //For debugging purposes only
    void RunSingle();

    //GO position members
    double x;
    double y;

    //Containers for all the aliens
    std::vector<std::unique_ptr<Squid>> _squids;
    std::vector<std::unique_ptr<Crab>> _crabs;
    std::vector<std::unique_ptr<Octopus>> _octos;

private:

    template <class T>
    void createAlien(const double start_y, std::vector<std::unique_ptr<T>> &alienVector);

    Direction _direction;
    bool _running{true};
    std::thread _thread;

    template <class T>
    void updateXPositions(std::vector<std::unique_ptr<T>> &alienVector);

    template <class T>
    void updateYPositions(std::vector<std::unique_ptr<T>> &alienVector);
    void updateGOPosition();

    //GO starting positions
    const double START_X{0};
    const double START_Y_OCTOS{0};
    const double START_Y_CRABS{40};
    const double START_Y_SQUIDS{80};

    //GO spacing
    const double SPACING_X{20};
    const double SPACING_Y{20};

    //GO size
    const double SIZE_X{212}; //Value in pixels
    const double SIZE_Y{108}; //Value in pixels

    //GO limits in pixels
    const double LIMIT_X{315};
    const double LIMIT_Y{200};

    //GO position update step
    const double STEP_X{5};
    const double STEP_Y{10};

    //GO Frame specifications
    const std::size_t kMsPerFrame{500};
};

#endif