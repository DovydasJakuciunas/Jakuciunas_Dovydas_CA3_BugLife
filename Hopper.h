//
// Created by dovyj on 17/04/2024.
//

#ifndef JAKUCIUNAS_DOVYDAS_CA3_BUGLIFE_HOPPER_H
#define JAKUCIUNAS_DOVYDAS_CA3_BUGLIFE_HOPPER_H


#include "Bug.h"

class Hopper : public Bug {
private:
    int hopLength;

public:
    Hopper(int bugId, pair<int, int> position, Direction dir, int bugSize, int hopLength);
    void move() override;
    string toString() override;
    bool isWayBlocked() override;

};


#endif //JAKUCIUNAS_DOVYDAS_CA3_BUGLIFE_HOPPER_H
