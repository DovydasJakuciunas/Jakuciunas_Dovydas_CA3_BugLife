//
// Created by dovyj on 10/04/2024.
//

#include <list>
#include <sstream>
#include <utility>
#include "Bug.h"
#include <random>
#include <iostream>

using namespace std;

Bug::Bug(char type, int bugId, pair<int,int> position, Direction dir, int bugSize)
        : bugType(type), id(bugId), position(std::move(position)), direction(dir), size(bugSize), alive(true) {}

string Bug::toString() {

}


void Bug::changeDirection() {
    random_device rd; // obtain a random number from hardware
    mt19937 gen(rd()); // seed the generator
    uniform_int_distribution<> distr(0, 3); // define the range

    int randomValue = distr(gen);

    switch (randomValue) {
        case 0:
            direction = Direction::North;
            break;
        case 1:
            direction = Direction::East;
            break;
        case 2:
            direction = Direction::South;
            break;
        case 3:
            direction = Direction::West;
            break;
        default:
            break;
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

void Bug::printLifeHistory() {
     cout<< id << " " << (bugType == 'C' ? "Crawler" : "Hopper") << " Path: ";
    for (const auto& pos : path) {
        cout << "(" << pos.first << "," << pos.second << ") ";   //Print the path of the bug
    }
    cout << (alive ? " Alive!" : " Eaten") << std::endl;    //Print if the bug is alive or eaten
}

list<pair<int, int>> Bug::getPath() {
    return path;
}


#include "Bug.h"
