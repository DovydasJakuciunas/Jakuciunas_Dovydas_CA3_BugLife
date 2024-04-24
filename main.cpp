#include <iostream>
#include <fstream>
#include <sstream>
#include "board.h"
#include "Crawler.h"
#include "Hopper.h"

void readFromFile();
Direction setDirection(int num);
int mainMenu();

vector<Bug*> bug_vector;

int main() {
    cout<< "Welcome to the BugLife Project"<<endl;
    readFromFile();


    while(true){
        int command = mainMenu();
        if (command == 1)
        {
            for(Bug* bug: bug_vector)
            {
                cout << bug->toString() << endl;
            }

        }
        else if (command == 2){
            cout<<"Whats the ID of the Bug?"<<endl;
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
    cout<<"Type 9: Exit Project"<<endl;

    int usersChoice;
    cin>> usersChoice;

    return usersChoice;
}

void readFromFile() {
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
