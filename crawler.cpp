//
// Created by dovyj on 10/04/2024.
//
using namespace std;

#include "crawler.h"

crawler :: crawler(char type, int bugId, int x, int y, Direction dir, int bugSize)
    : bug(type,bugId,x,y,dir,bugSize){
}

void crawler::move() {
    switch (direction) {
        case Direction::North:
            position.second--;
            break;
        case Direction::East:
            position.first++;
            break;

    }
}



