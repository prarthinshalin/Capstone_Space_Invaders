#include "globaloffensive.h"

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

Squid::Squid(double init_x, double init_y) {
    _alienType = AlienType::Squid;
    setPosition(init_x, init_y);
    bodySetup(kCharacterDirectory + kSquidDirectory);
}

void Squid::Simulate() {
    _threads.emplace_back(&Squid::RunSquid, this);
}

Crab::Crab(double init_x, double init_y) {
    setPosition(init_x, init_y);
    bodySetup(kCharacterDirectory + kCrabDirectory);
}

Octopus::Octopus(double init_x, double init_y) {
    setPosition(init_x, init_y);
    bodySetup(kCharacterDirectory + kOctopusFile);
}

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