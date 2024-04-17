//
// Created by dovyj on 17/04/2024.
//

#ifndef JAKUCIUNAS_DOVYDAS_CA3_BUGLIFE_HOPPER_H
#define JAKUCIUNAS_DOVYDAS_CA3_BUGLIFE_HOPPER_H


#include "bug.h"

class hopper : public bug{
private:
    int hopLength;

public:
    hopper(int bugId, pair<int, int> position, Direction dir, int bugSize,int hopLength);
    void move() override;

};


#endif //JAKUCIUNAS_DOVYDAS_CA3_BUGLIFE_HOPPER_H
