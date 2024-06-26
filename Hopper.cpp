//
// Created by dovyj on 17/04/2024.
//

#include <sstream>
#include "Hopper.h"

Hopper::Hopper(int bugId, pair<int, int> position, Direction dir, int bugSize, int hopLength) : Bug('H', bugId,
                                                                                                    position, dir,
                                                                                                    bugSize){
    this->id = bugId;
    this->position = position;
    this->direction = dir;
    this->size = bugSize;
    this->hopLength = hopLength;

}

string Hopper::toString() {
    stringstream ss;
    ss << "ID: "<<id << " Hopper ,Position(" << position.first << "," << position.second << "), Size: " << size << " ";
    switch (direction) {
        case Direction::North: ss << " ,North"; break;
        case Direction::South: ss << " ,South"; break;
        case Direction::East: ss << " ,East"; break;
        case Direction::West: ss << " ,West"; break;
    }
    ss << " " << ",Hop Length: " << hopLength << (alive ? " ,Alive" : " ,Dead") ;
    return ss.str();
}

void Hopper::move(int BoardX, int BoardY) {
    int directionsChecked = 0;
    bool moved = false;

    while (!moved)
    {
        if (directionsChecked == 6)
        {
            alive = false;
            break;
        }
        switch (Direction(direction)) {
            case Direction::North:
                if (position.second == 0 )
                {
                    changeDirection();
                    directionsChecked++;
                }
                else if (position.second - hopLength >= 0)
                {
                    position.second -= hopLength;
                    moved = true;
                }
                else if (position.second - hopLength < 0)
                {
                    position.second = 0;
                    moved = true;
                }
                break;
            case Direction::South:
                if (position.second == BoardY - 1)
                {
                    changeDirection();
                    directionsChecked++;
                }
                else if (position.second + hopLength <= BoardY - 1)
                {
                    position.second += hopLength;
                    moved = true;
                }
                else if (position.second + hopLength > BoardY - 1)
                {
                    position.second = BoardY - 1;
                    moved = true;
                }
                break;
            case Direction::West:
                if (position.first == 0)
                {
                    changeDirection();
                    directionsChecked++;
                }
                else if (position.first - hopLength >= 0)
                {
                    position.first -= hopLength;
                    moved = true;
                }
                else if (position.first - hopLength < 0)
                {
                    position.first = 0;
                    moved = true;
                }
                break;
            case Direction::East:
                if (position.first == BoardX - 1)
                {
                    changeDirection();
                    directionsChecked++;
                }
                else if (position.first + hopLength <= BoardX - 1)
                {
                    position.first += hopLength;
                    moved = true;
                }
                else if (position.first + hopLength > BoardX - 1)
                {
                    position.first = BoardX - 1;
                    moved = true;
                }
                break;
        }
    }
    path.push_back(position);
}
