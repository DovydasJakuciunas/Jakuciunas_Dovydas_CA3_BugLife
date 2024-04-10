//
// Created by dovyj on 10/04/2024.
//
using namespace std;

#include "crawler.h"

crawler::crawler(int id, pair<int, int> position, int dir, int size) : bug(id, position, dir, size) {
    this->id = id;
    this->position = position;
    this->dir = dir;
    this->size = size;
    this->alive = true;

}
