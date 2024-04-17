//
// Created by dovyj on 10/04/2024.
//
using namespace std;

#include "crawler.h"




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


}

crawler::crawler(int bugId1, pair<int, int> position, Direction dir1, int bugSize1) : bug('C', bugId1,
                                                                                                      position, dir1,
                                                                                                      bugSize1) {

}








