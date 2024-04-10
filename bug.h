//
// Created by dovyj on 10/04/2024.
//

#ifndef JAKUCIUNAS_DOVYDAS_CA3_BUGLIFE_BUG_H
#define JAKUCIUNAS_DOVYDAS_CA3_BUGLIFE_BUG_H

#include <utility>

using namespace std;

enum class Direction {
    North = 1,
    East = 2,
    South = 3,
    West = 4
};

class Bug {

protected:
    char bugType;
    int id;
    pair<int, int> position;
    Direction direction;
    int size;
    int hopLength;
    bool alive;
    list<std::pair<int, int>> path;

public:
    Bug(char type, int bugId, int x, int y, Direction dir, int bugSize, int hop = 0);
    virtual ~Bug() = default;

    virtual void move() = 0; // Pure virtual function

    bool isWayBlocked();

    string record();
};

#endif //JAKUCIUNAS_DOVYDAS_CA3_BUGLIFE_BUG_H
