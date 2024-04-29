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
    explicit Board(vector<Bug*> bug_vector);

    //Function 1 _ Simulate Board
    Board initialiseBoard();
    //Function 2 _ Simulate Display All Bugs
    void simulateDisplayAllBugs();
    //Function 3 _ Simulate Display Bug by ID
    void simulateDisplayBugById();
    //Function 4 _ Simulate Tapping the Board
    void simulateTap();
    //Function 5 _ Display Life History of All Bugs
    void displayLifeHistoryOfAllBugs();

    int getBoardX() const;
    int getBoardY() const;



};


#endif //JAKUCIUNAS_DOVYDAS_CA3_BUGLIFE_BOARD_H
