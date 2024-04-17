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

class bug {

protected:

    char bugType;
    int id;
    pair<int, int> position;
    Direction direction;
    int size;
    bool alive;
    list<std::pair<int, int>> path;

public:
    bug(char type, int bugId, pair<int, int> position, Direction dir, int bugSize);
    virtual ~bug() = default;   //Deconstructor

    virtual void move() = 0; // Pure virtual function

    bool isWayBlocked();
    string toString();
};

#endif //JAKUCIUNAS_DOVYDAS_CA3_BUGLIFE_BUG_H
