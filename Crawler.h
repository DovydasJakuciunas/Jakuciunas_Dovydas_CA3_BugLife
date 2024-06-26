//
// Created by dovyj on 10/04/2024.
//

#ifndef JAKUCIUNAS_DOVYDAS_CA3_BUGLIFE_CRAWLER_H
#define JAKUCIUNAS_DOVYDAS_CA3_BUGLIFE_CRAWLER_H

#include "Bug.h"
#include "Board.h"

class Crawler : public Bug {

public :
    Crawler(int bugId1, pair<int, int> position, Direction dir1, int bugSize1);
    void move(int boardX, int boardY) override;
    string toString() override;

};


#endif //JAKUCIUNAS_DOVYDAS_CA3_BUGLIFE_CRAWLER_H
