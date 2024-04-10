//
// Created by dovyj on 10/04/2024.
//

#include <list>

enum class Direction{
    North = 1,
    East = 2 ,
    South  = 3 ,
    West  =4
};

class Bug{
protected:
    int id;
    std:: pair<int,int> position;
    Direction direction;
    int size;
    bool alive;
    std::list<std::pair<int,int>> path;

public:
    Bug(int bugId, int x, int y, Direction dir, int bugSize);
    virtual ~Bug() = default;

    virtual void move() = 0;

    bool isWayBlocked();
};

#include "Bug.h"
