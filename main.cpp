#include <iostream>
#include <fstream>
#include <sstream>
#include "Board.h"
#include "Crawler.h"
#include "Hopper.h"

void readFromFile();
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
        if (command == 1)       board->simulateDisplayAllBugs();

        else if (command == 2)  board->simulateDisplayBugById();
        else if(command == 3)
        {
            board->simulateTap();
        }
        else if (command == 9)
        {
            cout<< "Thank you for Using the BugLife Project"<< endl;
            break;
        }
        else{
            cout<< "Invalid Command ";

        }
    }
}

int mainMenu() {
    cout<< "Commands:"<<endl;
    cout<<"Type 1: Display All Bugs"<< endl;
    cout<<"Type 2: Display Bug by ID"<<endl;
    cout<<"Type 3: Tap The Board"<<endl;
    cout<<"Type 9: Exit Project"<<endl;

    int usersChoice;
    cin>> usersChoice;

    return usersChoice;
}



