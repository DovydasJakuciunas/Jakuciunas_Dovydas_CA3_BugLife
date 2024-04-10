//
// Created by dovyj on 10/04/2024.
//
using namespace std;

#include "crawler.h"

crawler :: crawler(char type, int bugId, int x, int y, Direction dir, int bugSize)
    : bug(type,bugId,x,y,dir,bugSize){
}
void crawler::move() {
    // Move one unit in the current direction
    switch (direction) {
        case Direction::North:
            position.second--;
            break;
        case Direction::East:
            position.first++;
            break;
        case Direction::South:
            position.second++;
            break;
        case Direction::West:
            position.first--;
            break;
    }

    // Check if the way is blocked
    if (isWayBlocked()) {
        // Change direction until a clear path is found
        for (int newDir = 1; newDir <= 4; ++newDir) {
            direction = static_cast<Direction>(newDir);
            if (!isWayBlocked())
                break;
        }
    }
}




