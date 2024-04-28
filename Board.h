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
    int width{};
    int height{};

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
    void printBoard();

    void readFromFile();

    void simulateTap();

    explicit Board(vector<Bug*> bug_vector);

    //Function 1 _ Simulate Board
    static Board initialiseBoard();
    //Function 2 _ Simulate Display All Bugs
    void simulateDisplayAllBugs();
    //Function 3 _ Simulate Display Bug by ID
    void simulateDisplayBugById();
    //Function 4 _ Simulate Tapping the Board
    void simulateInitialiseBoard();



};


#endif //JAKUCIUNAS_DOVYDAS_CA3_BUGLIFE_BOARD_H
