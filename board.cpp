//
// Created by dovyj on 17/04/2024.
//

#include <fstream>
#include <iostream>
#include "board.h"

using namespace std;

int board::readFromFile() { //read from file
    ifstream fin("bugs.txt");
    if(fin)
    {
        string line;
        while(getline(fin,line)) // ensures we haven't reached the end of file (eof)
        {
            string tempLine; // creates a variable to store each word we read in from the file.
            stringstream ss

            char bugType;


        }
    }
    else
    {
        cout << "Unable to open file" <<endl;
    }
    return 0;
}





