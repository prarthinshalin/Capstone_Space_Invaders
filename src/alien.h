#ifndef ALIEN_H
#define ALIEN_H

#include <SDL2/SDL.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <thread>

enum AlienType {
    noAlien,
    kSquid,
    kCrab,
    kOctopus,
    kUFO
};

class Alien {
public:
    //Constructor & Destructor

    //Setters and getters
    bool isAlive();
    void setPosition(double x, double y);
    void getPosition(double &x, double &y);
    void shiftHorizontal(const double step_size);
    void shiftVertical(const double step_size);
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

#endif