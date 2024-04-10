//
// Created by dovyj on 10/04/2024.
//

#ifndef JAKUCIUNAS_DOVYDAS_CA3_BUGLIFE_CRAWLER_H
#define JAKUCIUNAS_DOVYDAS_CA3_BUGLIFE_CRAWLER_H

#include "bug.h"

class crawler : public bug{

public :
    crawler(char type, int bugId, int x, int y, Direction dir, int bugSize);
    void move() override;
};


#endif //JAKUCIUNAS_DOVYDAS_CA3_BUGLIFE_CRAWLER_H
