#ifndef GLOBALOFFENSIVE_H
#define GLOBALOFFENSIVE_H

#include <vector>
#include <memory>
#include <SDL2/SDL.h>
#include <thread>

enum AlienType {
    noAlien,
    Squid,
    Crab,
    Octopus,
    UFO
};

class Alien {
public:
    //Constructor & Destructor

    //Setters and getters
    bool isAlive();
    void setPosition(double x, double y);
    void getPosition(double &x, double &y);
    AlienType getAlienType();

    //typical behaviour methods
    //Virtual functions to be implemented by derived classes
    void bodySetup(const std::string &path);
    //irtual void Update() = 0;

    //member variables
    AlienType _alienType = AlienType::noAlien;
    double _pos_x, _pos_y;
    bool _alive{true};
    std::vector<SDL_Point> _body;
    std::vector<std::thread> _threads;
};

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

class Crab : public Alien {
public:
    const std::string kCharacterDirectory{"../characters/"};
    const std::string kCrabDirectory{"crab"};

    Crab(double init_x, double init_y);
};

class Octopus : public Alien {
public:
    const std::string kCharacterDirectory{"../characters/"};
    const std::string kOctopusFile{"octopus"};

    Octopus(double init_x, double init_y);
};


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