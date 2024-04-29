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
    uniform_int_distribution<> distr(1, 4); // define the range

    int randomValue = distr(gen);

    switch (randomValue) {
        case 1:
            direction = Direction::North;
            break;
        case 2:
            direction = Direction::East;
            break;
        case 3:
            direction = Direction::South;
            break;
        case 4:
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

string Bug::printLifeHistory() {
    ostringstream oss;
    oss<< id << " " << (bugType == 'C' ? "Crawler" : "Hopper") << " Path: ";
    for (const auto& pos : path) {
        oss << "(" << pos.first << "," << pos.second << ") ";   //Print the path of the bug
    }
    oss << (alive ? " Alive!" : " Eaten") << endl;    //Print if the bug is alive or eaten
    return oss.str();
}

list<pair<int, int>> Bug::getPath() {
    return path;
}

bool Bug::isAlive() {
    return alive;
}

int Bug::getSize() {
    return size;
}

void Bug::setAlive(bool b) {
    alive = b;
}
void Bug::setSize(int s) {
    size = s;
}


#include "Bug.h"
