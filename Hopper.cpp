//
// Created by dovyj on 17/04/2024.
//

#include <sstream>
#include "Hopper.h"


Hopper::Hopper(int bugId, pair<int, int> position, Direction dir, int bugSize, int hopLength) : Bug('H', bugId,
                                                                                                    position, dir,
                                                                                                    bugSize){
    this->hopLength = hopLength;

}

string Hopper::toString() {
    stringstream ss;
    ss << id << " Hopper (" << position.first << "," << position.second << ") Size:" << size << " ";
    switch (direction) {
        case Direction::North: ss << " ,North"; break;
        case Direction::South: ss << " ,South"; break;
        case Direction::East: ss << " ,East"; break;
        case Direction::West: ss << " ,West"; break;
    }
    ss << " " << hopLength << (alive ? " Alive" : " Dead");
    return ss.str();
}


void Hopper::move() {
    // Move hopLength units in the current direction
    switch (direction) {
        case Direction::North:
            position.second -= hopLength;
            break;
        case Direction::East:
            position.first += hopLength;
            break;
        case Direction::South:
            position.second += hopLength;
            break;
        case Direction::West:
            position.first -= hopLength;
            break;
    }


}

