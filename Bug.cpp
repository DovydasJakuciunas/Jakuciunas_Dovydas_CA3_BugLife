//
// Created by dovyj on 10/04/2024.
//

#include <list>
#include <sstream>
#include <utility>
#include "Bug.h"

using namespace std;

Bug::Bug(char type, int bugId, pair<int,int> position, Direction dir, int bugSize)
        : bugType(type), id(bugId), position(std::move(position)), direction(dir), size(bugSize), alive(true) {}

bool Bug::isWayBlocked() {
    int boardSize = 10; //Size of Board is 10
    switch (direction) {
        case Direction::North:
            return position.second == 0;
        case Direction::East:
            return position.first == boardSize - 1;
        case Direction::South:
            return position.second == boardSize - 1;
        case Direction::West:
            return position.first == 0;
        default:
            return false; // Unknown direction
    }
}

string Bug::toString() {

}

int Bug::getID() const {
    return this->id;

}

void Bug::changeDirection() {
    srand(time(nullptr)); // use current time as seed for random generator
    int randomValue = rand() % 4 + 1; // generates a random number between 1 and 4

    if (randomValue == 1)
    {
        this->direction = Direction::West;
    }
    else if(randomValue ==2)
    {
        this->direction = Direction::East;
    }
    else if (randomValue == 3)
    {
        this->direction = Direction::North;
    }
    else if (randomValue == 4)
    {
       this->direction = Direction::South;
    }
    else
    {
        this->direction = direction;
    }
}


#include "Bug.h"
