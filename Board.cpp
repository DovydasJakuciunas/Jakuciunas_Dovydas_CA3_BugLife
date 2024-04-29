//
// Created by dovyj on 17/04/2024.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <utility>
#include "Board.h"
#include "Crawler.h"
#include "Hopper.h"

void displayChoiceOfBoard();

using namespace std;


void Board::tap() {
   cout<<"****Tapping Board****"<<endl;
    for (Bug* bug : bug_vector) {
        bug->move(width, height);
    }
    printBoard();
    cout<<endl;
}
void Board::simulateTap() {
    tap();
}

Board::Board(vector<Bug *> bug_vector) {
this->bug_vector = std::move(bug_vector);
}



//Function 2
void Board::displayAllBugs() {
    for(Bug* bug: bug_vector)
    {
        cout << bug->toString() << endl;
    }
}
void Board::simulateDisplayAllBugs() {
    displayAllBugs();
}

//Function 3
void Board::displayBugById() {
    cout << "Whats the ID of the Bug?" << endl;
    int id;
    cin>>id;
    for(Bug* bug: bug_vector)
    {
        if (bug->getID() == id)
        {
            cout<< bug->toString()<<endl;
        }
    }
}
void Board::simulateDisplayBugById(){
    displayBugById();
}

//Enum of Directions
Direction setDirection(int num) {
    if (num == 1) {
        return Direction::North;
    } else if (num == 2) {
        return Direction::East;
    } else if (num == 3) {
        return Direction::South;
    } else if (num == 4){
        return Direction::West;
    }
    return Direction::West;
}

//Reading From File
void Board::readFromFile() {
    bug_vector.clear();


    ifstream fin("bugs.txt");

    if(fin)
    {
        string line;
        while(getline(fin,line)) // ensures we haven't reached the end of file (eof)
        {

            string tempLine; // creates a variable to store each word we read in from the file.
            stringstream ss(line);  //Allows string to be treated as stream
            getline(ss,tempLine,';');
            if (tempLine[0] == 'C')
            {
                getline(ss,tempLine,';');
                int id = stoi(tempLine);
                getline(ss,tempLine,';');
                int xCord = stoi(tempLine);
                getline(ss,tempLine,';');
                int yCord = stoi(tempLine);
                getline(ss,tempLine,';');
                int dir = stoi(tempLine);
                Direction look =setDirection(dir);
                getline(ss,tempLine,';');
                int size = stoi(tempLine);

                Bug * pCrawler = new Crawler(id, make_pair(xCord, yCord), look, size);
                bug_vector.push_back(pCrawler);
            }

            else if (tempLine[0] == 'H')
            {
                getline(ss,tempLine,';');
                int id = stoi(tempLine);
                getline(ss,tempLine,';');
                int xCord = stoi(tempLine);
                getline(ss,tempLine,';');
                int yCord = stoi(tempLine);
                getline(ss,tempLine,';');
                int dir = stoi(tempLine);
                Direction look =setDirection(dir);
                getline(ss,tempLine,';');
                int size = stoi(tempLine);
                getline(ss,tempLine,';');
                int hopLength = stoi(tempLine);

                Bug * pHopper = new Hopper(id, make_pair(xCord, yCord), look, size, hopLength);
                bug_vector.push_back(pHopper);
            }
            else
            {
                cout<<"File Structure is INCORRECT!!!!"<<endl;
            }


        }
    }
    else
    {
        cout << "*********************Unable to open file*********************" <<endl;
    }


}

//Function 1
Board Board::initialiseBoard(){
    cout << "simulateInitialiseBoard() function called" << endl;
    displayChoiceOfBoard();
    int choice = 0;
    cout << "Please enter your choice: ";
    cin >> choice;
    while (choice < 1 || choice > 2)
    {
        cout << "Invalid choice. Please enter your choice: ";
        cin >> choice;
    }

    if (choice == 1)
    {
        cout << "Default Board Size" << endl;
        width =10;
        height = 10;
        readFromFile();
        return {};
    }
    else
    {

        cout << "Width: ";
        cin >> width;

        cout << "Height: ";
        cin >> height;

        readFromFile();

        return {width, height};
    }


}
void displayChoiceOfBoard() {
    cout << "1. Default Board Size"<< endl;
    cout << "2. Custom Board Size"<< endl;
}

//Function 5
void Board::displayLifeHistoryOfAllBugs() {
    for (Bug* bug : bug_vector) {
        bug->printLifeHistory();
    }
}

//Constructors
Board::Board() {
    this->height = 10;
    this->width = 10;
}
Board::Board(int width, int height) {
    this->width = width;
    this->height = height;
}


//Printing The Board
void Board::printBoard() {
    for (int i = 0; i < height; ++i)//Print Vertical Lines
         {
        for (int j = 0; j < width; ++j)//Print Horizontal Lines
            {
            cout<<"+------";
        }
        cout<<"+"<<endl;
        for (int j = 0; j< width; ++j){
            cout<<"|";
            bool isBug = false;

            for(Bug* bug: bug_vector){                  //Adds Bug if Within the Cell
                if(bug->getPosition().first == j && bug->getPosition().second == i){
                    cout<<bug->getType()<<"-"<<bug->getID();
                    isBug = true;
                }
            }
            if (!isBug){
                cout<<"      "; //Prints 6 spaces for empty cells
            }
        }
        cout<<"|"<<endl;
    }
    for(int j = 0; j < width; j++) {
        cout << "+------";
    }
    cout << "+" << endl;
}

//getBoardX and BoardY
int Board::getBoardX() const {
    return width;
}

int Board::getBoardY() const {
    return height;
}






