//
// Created by dovyj on 10/04/2024.
//

#ifndef JAKUCIUNAS_DOVYDAS_CA3_BUGLIFE_CRAWLER_H
#define JAKUCIUNAS_DOVYDAS_CA3_BUGLIFE_CRAWLER_H

#include "bug.h"

class crawler : public bug{

public :
    crawler(int bugId1, pair<int, int> position, Direction dir1, int bugSize1);
    void move() override;


};


#endif //JAKUCIUNAS_DOVYDAS_CA3_BUGLIFE_CRAWLER_H
