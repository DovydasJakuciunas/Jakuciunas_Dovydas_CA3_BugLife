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
    int width;
    int height;

protected:




    //Function 2
    void displayAllBugs();
    //Function 3
    void displayBugById();
    //Function 4
    void tap();

public:
    //Constructors
    Board();
    Board(int width, int height);

    //Printing Board

    void readFromFile();

    void simulateTap();

    explicit Board(vector<Bug*> bug_vector);
    //Function 1 _ Simulate
    void simulateDisplayAllBugs();
    //Function 2 _ Simulate
    void simulateDisplayBugById();
    //Function 3 _ Simulate
    void simulateInitialiseBoard();


};


#endif //JAKUCIUNAS_DOVYDAS_CA3_BUGLIFE_BOARD_H
