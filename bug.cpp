//
// Created by dovyj on 10/04/2024.
//

#include <list>
#include "bug.h"

Bug::Bug(int bugId, int x, int y, Direction dir, int bugSize)
        : id(bugId), position(std::make_pair(x, y)), direction(dir), size(bugSize), alive(true) {}

bool Bug::isWayBlocked() {
    int boardSize = 20; // Assuming the board size is 20x20
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

#include "bug.h"
