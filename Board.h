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
    vector<Bug*> deadBugs;
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

    //Function 1 _ Board
    Board initialiseBoard();
    //Function 2 _ Display All Bugs
    void simulateDisplayAllBugs();
    //Function 3 _ Display Bug by ID
    void simulateDisplayBugById();
    //Function 4 _ Tapping the Board
    void simulateTap();
    //Function 5 _ Display Life History of All Bugs
    void displayLifeHistoryOfAllBugs();
    //Function 6 _ Write to Files
    void writeToFile();
    //Function 7 _ Print All Cells
    void displayAllCells();
    //Function 8 _ Run Simulation
    void runSimulation();

    int getBoardX() const;
    int getBoardY() const;


    void bugFightAndEat();
    void removeDeadBug();


};


#endif //JAKUCIUNAS_DOVYDAS_CA3_BUGLIFE_BOARD_H
