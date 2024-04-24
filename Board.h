//
// Created by dovyj on 17/04/2024.
//

#ifndef JAKUCIUNAS_DOVYDAS_CA3_BUGLIFE_BOARD_H
#define JAKUCIUNAS_DOVYDAS_CA3_BUGLIFE_BOARD_H


#include <vector>
#include "Bug.h"

class Board {
private:
    vector<Bug*> bug_vector;


protected:



    //Function 1
    void displayAllBugs();
    //Function 2
    void displayBugById();
    void tap();

public:
    void readFromFile();

    void simulateTap();

    explicit Board(vector<Bug*> bug_vector);
    //Function 1
    void simulateDisplayAllBugs();
    //Function 2
    void simulateDisplayBugById();
};


#endif //JAKUCIUNAS_DOVYDAS_CA3_BUGLIFE_BOARD_H
