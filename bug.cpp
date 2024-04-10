//
// Created by dovyj on 10/04/2024.
//

#include <list>
#include <sstream>
#include "bug.h"

Bug::Bug(char type, int bugId, int x, int y, Direction dir, int bugSize, int hop)
        : bugType(type), id(bugId), position(std::make_pair(x, y)), direction(dir), size(bugSize), hopLength(hop), alive(true) {}

bool Bug::isWayBlocked() {
    int boardSize = 10; //Size of board is 10
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

string Bug::record(){
    ostringstream oss;
    oss <<bugType<< ";" << id << ";" << position.first << ";" << position.second<< ";" << size;
    if(bugType =='H'){
        oss<< ";" << hopLength;
    }
    oss << "\n";
    return oss.str();
}

#include "bug.h"
