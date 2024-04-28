//
// Created by dovyj on 10/04/2024.
//

#ifndef JAKUCIUNAS_DOVYDAS_CA3_BUGLIFE_BUG_H
#define JAKUCIUNAS_DOVYDAS_CA3_BUGLIFE_BUG_H

#include <utility>
#include <string>

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
    bool alive;
    //list<std::pair<int, int>> path;

public:
    Bug(char type, int bugId, pair<int, int> position, Direction dir, int bugSize);
    virtual ~Bug() = default;

    virtual void move() = 0; //  Pure virtual function
    virtual bool isWayBlocked() = 0;
    virtual string toString();
    virtual void changeDirection();

    //Function 3

    //Getter

    pair<int, int> getPosition();
    char getType() const;
    int getID() const;
};

#endif //JAKUCIUNAS_DOVYDAS_CA3_BUGLIFE_BUG_H
