//
// Created by dovyj on 10/04/2024.
//
using namespace std;

#include <sstream>
#include "Crawler.h"



void Crawler::move(int boardX, int boardY) {
    if (isWayBlocked(Board(boardX, boardY))) {
        changeDirection();
    } else {
        switch (direction) {
            case Direction::North:
                if (position.second > 0) {
                    position.second--;
                }
                break;
            case Direction::South:
                if (position.second < boardY - 1) {
                    position.second++;
                }
                break;
            case Direction::East:
                if (position.first < boardX - 1) {
                    position.first++;
                }
                break;
            case Direction::West:
                if (position.first > 0) {
                    position.first--;
                }
                break;
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

bool Crawler::isWayBlocked(const Board& board) {
    int boardX = board.getBoardX();
    int boardY = board.getBoardY();
    switch (direction) {
        case Direction::North:
            if (position.second == 0)
            {
                return true;
            }
            break;
        case Direction::South:
            if ( position.second == boardY - 1)
            {
                return true;
            }
            break;
        case Direction::East:
            if ( position.first == boardX - 1)
            {
                return true;
            }
            break;
        case Direction::West:
            if ( position.first == 0)
            {
                return true;
            }
            break;
        default:
            return false;
    }
    return false;
}


