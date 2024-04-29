#include <iostream>
#include <fstream>
#include <sstream>
#include "Board.h"
#include "Crawler.h"
#include "Hopper.h"

using namespace std;

Direction setDirection(int num);
int mainMenu();

void Commands(Board *board);

vector<Bug*> bug_vector_temp;

int main() {
    cout<< "Welcome to the BugLife Project"<<endl;
    Board* board = new Board(bug_vector_temp);
    board->readFromFile();

    Commands(board);



}

void Commands(Board* board) {
    while(true){
        int command = mainMenu();
        switch (command) {
            case 1:
                board->initialiseBoard();
                break;
            case 2:

                board->simulateDisplayAllBugs();
                break;
            case 3:
                board->simulateDisplayBugById();
                break;
            case 4:
                board->simulateTap();
                break;
            case 5:
                board->printBoard();
                break;
            case 9:
                cout<< "Thank you for Using the BugLife Project"<< endl;
                return;
            default:
                cout<< "Invalid Command \n";
                break;
        }
    }
}

int mainMenu() {
    cout<< "Commands:"<<endl;
    cout<<"Type 1: Initialize Bug Board "<< endl;
    cout<<"Type 2: Display All Bugs " << endl;
    cout<<"Type 3: Display Bug by ID"<<endl;
    cout<<"Type 4: Tap The Board"<<endl;
    cout<<"Type 9: Exit Project"<<endl;

    int usersChoice;
    cin>> usersChoice;

    return usersChoice;
}



