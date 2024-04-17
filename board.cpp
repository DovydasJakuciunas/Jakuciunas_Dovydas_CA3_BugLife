//
// Created by dovyj on 17/04/2024.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "board.h"
#include "crawler.cpp"
#include "hopper.h"

using namespace std;

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
}


int board::readFromFile() { //read from file
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

                crawler * crawler = new class crawler(id, make_pair(xCord,yCord),look,size);

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
                hopper *hopper = new class hopper(id, make_pair(xCord, yCord), look, size, hopLength);

            }
            else
            {
                cout<<"File Structure is INCORRECT!!!!"<<endl;
            }


        }
    }
    else
    {
        cout << "Unable to open file" <<endl;
    }
    return 0;
}





