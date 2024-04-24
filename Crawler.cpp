//
// Created by dovyj on 10/04/2024.
//
using namespace std;

#include "Crawler.h"




void Crawler::move() {
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

Crawler::Crawler(int bugId1, pair<int, int> position, Direction dir1, int bugSize1) : Bug('C', bugId1,
                                                                                          position, dir1,
                                                                                          bugSize1) {
    this->id = bugId1;
    this->position = position;
    this->direction = dir1;
    this-> size = bugSize1;

}








