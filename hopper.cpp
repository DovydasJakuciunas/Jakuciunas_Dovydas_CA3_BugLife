//
// Created by dovyj on 17/04/2024.
//

#include "hopper.h"


hopper::hopper(int bugId, pair<int, int> position, Direction dir, int bugSize, int hopLength) : bug('H', bugId,
                                                                                                    position, dir,
                                                                                                    bugSize){
    this->hopLength = hopLength;

}


void hopper::move() {
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

