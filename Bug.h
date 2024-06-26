//
// Created by dovyj on 10/04/2024.
//

#ifndef JAKUCIUNAS_DOVYDAS_CA3_BUGLIFE_BUG_H
#define JAKUCIUNAS_DOVYDAS_CA3_BUGLIFE_BUG_H

#include <utility>
#include <string>
#include <list>

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
    list<pair<int, int>> path;

public:
    Bug(char type, int bugId, pair<int, int> position, Direction dir, int bugSize);
    virtual ~Bug() = default;

    virtual void move(int boardX, int boardY) = 0; //  Pure virtual function
    virtual string toString();
    virtual void changeDirection();


    string printLifeHistory();

    //Getter
    pair<int, int> getPosition();
    char getType() const;
    int getID() const;
    bool isAlive();
    int getSize();

    void setSize(int s);
    void setAlive(bool b);
};

#endif //JAKUCIUNAS_DOVYDAS_CA3_BUGLIFE_BUG_H
