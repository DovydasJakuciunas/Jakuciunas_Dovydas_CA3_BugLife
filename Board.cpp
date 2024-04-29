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
#include <algorithm>

void displayChoiceOfBoard();

using namespace std;

//Function 4
void Board::tap() {
   cout<<"****Tapping Board****"<<endl;
    for (Bug* bug : bug_vector) {
        bug->move(width, height);
    }
    bugFightAndEat();
    printBoard();
    cout<<endl;
}

void Board::bugFightAndEat() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            vector<Bug*> oneCellBugs;
            for (Bug* bug: bug_vector) {
                if (bug->getPosition().first == j && bug->getPosition().second == i && bug->isAlive()) {    //Check if there are bugs in the cell
                    oneCellBugs.push_back(bug);
                }
            }
            if (oneCellBugs.size() > 1){
                Bug* maxBug = *max_element(oneCellBugs.begin(), oneCellBugs.end(), [](Bug* a, Bug* b) { return a->getSize() < b->getSize(); }); //Finding the biggest bug
                vector<Bug*> maxBugs;
                for(Bug* bug: oneCellBugs){
                    if(bug->getSize() == maxBug->getSize()){
                        maxBugs.push_back(bug);
                    }
                    else
                    {
                        bug->setAlive(false);
                        maxBug->setSize(maxBug->getSize() + bug->getSize());
                    }
                }
                if(maxBugs.size() > 1){
                    int chosenBug = rand() % maxBugs.size();
                    for (int k = 0; k < maxBugs.size(); ++k) {
                        if (k != chosenBug){
                            maxBugs[k]->setAlive(false);
                            maxBug->setSize(maxBug->getSize() + maxBugs[k]->getSize());
                        }
                    }
                }
            }
        }
    }
    removeDeadBug();
}

void Board::removeDeadBug() {
    bug_vector.erase(std::remove_if(bug_vector.begin(), bug_vector.end(), [this](Bug* bug) {
        bool isDead = !bug->isAlive();
        if (isDead) {
            deadBugs.push_back(bug);
        }
        return isDead;
    }), bug_vector.end());
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
        cout<<bug->printLifeHistory();
    }
}

//Function 6
void Board::writeToFile() {
    ofstream file("bug_life_history.out");
    if (!file.is_open()) {
        cerr << "Unable to open file" << endl;
        return;
    }

    if (bug_vector.empty()) {
        cerr << "Bug vector is empty" << endl;
        return;
    }

    for (Bug* bug : bug_vector) {
        file << bug->printLifeHistory() << endl;
    }
    for (Bug* bug : deadBugs) {
        file << bug->printLifeHistory() << endl;
    }

    file.close();
    cout << "File Written Successfully" << endl;

}



//Function 7
void Board::displayAllCells() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            string cellCount;
            //Check if bugs are in the Cell
            for (Bug* bug: bug_vector) {
                if (bug->getPosition().first == j && bug->getPosition().second == i) {
                    cellCount += bug->toString();
                }
            }
            //If there are no bugs in the Cell
            if (cellCount.empty()) {
                cout << "Cell: " << j << "," << i << " is Empty" << endl;
            } else {
                cout << "Cell: " << j << "," << i << " has " << cellCount << endl;
            }
        }

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

void Board::runSimulation() {
    int i = 0;
    while (bug_vector.size() > 1)
    {
        cout << "Round: " << i << endl;
        tap();
        i++;
    }
    cout << "Rounds: " << i << endl;
    printBoard();
    cout << "Winner: " << bug_vector[0]->getID() << endl;
    writeToFile();

}












