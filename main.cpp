#include <iostream>
#include <fstream>
#include <sstream>
#include "board.h"
#include "Crawler.h"
#include "Hopper.h"

void readFromFile();
Direction setDirection(int num);

int main() {

    readFromFile();
}

void readFromFile() {
    ifstream fin("bugs.txt");

    vector<Bug*> bug_vector;
    if(fin)
    {
        string line;
        while(getline(fin,line)) // ensures we haven't reached the end of file (eof)
        {

            string tempLine; // creates a variable to store each word we read in from the file.
            stringstream ss(line);  //Allows string to be treated as stream
            getline(ss,tempLine,';');
            cout<<"File Opened"<<endl;
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
}

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
