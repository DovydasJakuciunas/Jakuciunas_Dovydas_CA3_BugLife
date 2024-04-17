//
// Created by dovyj on 10/04/2024.
//

#include <list>
#include <sstream>
#include <utility>
#include "bug.h"

bug::bug(char type, int bugId, pair<int,int> position, Direction dir, int bugSize)
        : bugType(type), id(bugId), position(std::move(position)), direction(dir), size(bugSize), alive(true) {}

bool bug::isWayBlocked() {
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

string bug::toString() {
    ostringstream oss;
    oss <<bugType<< ";" << id << ";" << position.first << ";" << position.second<< ";" << size;

    oss << "\n";
    return oss.str();
}



#include "bug.h"
