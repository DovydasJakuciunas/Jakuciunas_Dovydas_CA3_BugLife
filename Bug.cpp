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

string Bug::toString() {

}


void Bug::changeDirection() {
    srand(time(nullptr)); // use current time as seed for random generator
    int randomValue = rand() % 4 + 1; // generates a random number between 1 and 4

    switch (randomValue) {
        case 1:
            direction = Direction::North;
        case 2:
            direction = Direction::East;
        case 3:
            direction = Direction::South;
            case 4:
                direction = Direction::West;
    }

}

pair<int, int> Bug::getPosition() {
    return this->position;
}


char Bug::getType() const {
    return this-> bugType;
}

int Bug::getID() const {
    return this->id;
}


#include "Bug.h"
