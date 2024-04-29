//
// Created by dovyj on 10/04/2024.
//
using namespace std;

#include <sstream>
#include "Crawler.h"



void Crawler::move(int BoardX, int BoardY) {
    bool moved = false;
    int directionsChecked = 0;
    
    while (!moved)
    {
        if (directionsChecked == 6)
        {
            alive = false;
            break;
        }
        switch (direction) {
            case Direction::North:
                if (position.second > 0)
                {
                    position.second -= 1;
                    moved = true;
                }
                else
                {
                    changeDirection();
                    directionsChecked++;
                }
                break;
            case Direction::South:
                if (position.second < BoardY - 1)
                {
                    position.second += 1;
                    moved = true;
                }
                else
                {
                    changeDirection();
                    directionsChecked++;
                }
                break;
            case Direction::West:
                if (position.first > 0)
                {
                    position.first -= 1;
                    moved = true;
                }
                else
                {
                    changeDirection();
                    directionsChecked++;
                }
                break;
            case Direction::East:
                if (position.first < BoardX - 1)
                {
                    position.first += 1;
                    moved = true;
                }
                else
                {
                    changeDirection();
                    directionsChecked++;
                }
                break;
        }
    }
    path.push_back(position);
}

Crawler::Crawler(int bugId, pair<int, int> position, Direction dir, int bugSize) : Bug('C', bugId,
                                                                                          position, dir,
                                                                                          bugSize) {
    this->id = bugId;
    this->position = position;
    this->direction = dir;
    this-> size = bugSize;

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



void Crawler::setPosition(pair<int, int> pair) {
    position = pair;

}

Direction Crawler::getDirection() {
     return direction;

}




