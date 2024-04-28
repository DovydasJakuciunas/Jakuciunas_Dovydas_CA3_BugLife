//
// Created by dovyj on 10/04/2024.
//
using namespace std;

#include <sstream>
#include "Crawler.h"



void Crawler::move(int boardX, int boardY) {
    while(!isWayBlocked()) {
        pair<int, int> newPosition = position;
        switch (direction) {
            case Direction::North:
                newPosition.second--;
                break;
            case Direction::East:
                newPosition.first++;
                break;
            case Direction::South:
                newPosition.second++;
                break;
            case Direction::West:
                newPosition.first--;
                break;
        }
        if (newPosition.first >= 0 && newPosition.first < boardX && newPosition.second >= 0 && newPosition.second < boardY) {
            position = newPosition;
        } else {
            direction = static_cast<Direction>((static_cast<int>(direction) + 1) % 4);
        }
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

string Crawler::toString() {
    stringstream ss; //allows String to be treated as Stream
    ss<< "ID: "<<id<<" Crawler ,Position(" << position.first << "," << position.second << "), Size: " << size;
    switch (direction) {
        case Direction::North: ss<<" ,North"; break;
        case Direction::South: ss<<" ,South"; break;
        case Direction::East: ss<<" ,East"; break;
        case Direction::West: ss<<" ,West"; break;
    }
    ss << (alive?" ,Alive" : " ,Dead");

    return ss.str();
}
bool Crawler::isWayBlocked() {


    switch (direction) {
        case Direction::North:
            if (position.second == 0){
                return false;
            }
        case Direction::South: if (position.second == 9){
                return false;
            }
        case Direction::East: if (position.first == 9){
                return false;
            }
        case Direction::West: if (position.first == 0){
                return false;
            }
        default:
            return true;

    }

}












