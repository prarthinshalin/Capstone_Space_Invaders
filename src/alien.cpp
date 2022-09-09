#include "alien.h"

bool Alien::isAlive() { 
    return _alive; 
}

void Alien::setPosition(double x, double y) {
    _pos_x = x;
    _pos_y = y;
}

void Alien::getPosition(double &x, double &y) {
    x = _pos_x;
    y = _pos_y;
}

AlienType Alien::getAlienType() {
    return _alienType;
}

void Alien::bodySetup(const std::string &path) {
    std::string temp1, temp2, line;
    double rows, columns, var;

    std::ifstream instream(path);
    if(instream.is_open()) {
        //Getting the first line which is the width of the body
        std::getline(instream, temp1);
        rows = std::stod(temp1);
        

        //Getting the first line which is the height of the body
        std::getline(instream, temp2);
        columns = std::stod(temp2);

        for(int i = 0; i < rows; i++) {
            std::getline(instream, line);
            std::istringstream lineStream(line);
            for(int j = 0; j < columns; j++) {
                lineStream >> var;
                if(var > 0) {
                    SDL_Point tempPoint;
                    tempPoint.x = _pos_x + j;
                    tempPoint.y = _pos_y + i;
                    _body.emplace_back(tempPoint);
                } 
            }
        }
    } else { std::cout << "File could not be opened!\n"; }
}