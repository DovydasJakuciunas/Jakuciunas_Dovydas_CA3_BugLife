//
// Created by dovyj on 17/04/2024.
//

#include "Hopper.h"


Hopper::Hopper(int bugId, pair<int, int> position, Direction dir, int bugSize, int hopLength) : Bug('H', bugId,
                                                                                                    position, dir,
                                                                                                    bugSize){
    this->hopLength = hopLength;

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

