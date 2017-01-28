//CSCE 2110 Program 1: Integer Hash Table Implementation with Closed Hashing. 
//Author: Alexander Hollis
//Contact: awh0045@unt.edu
//Collaboration Group (in class): Isaias Delgado, Michele Hindman, Josseline Rodriguez
//Files required: main.cpp, hash.h, hash.cpp
//Compiled on CSE Machine 01


#include <cstdlib>
#include <iostream>
#include <sstream>
#include "hash.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Table hashT(7);

    bool quit = false;

    string input, command;
    int comm;

    istringstream ss;

    while (quit == false) {

        cout << "set> ";
        getline(cin, input); //store entire line of input for user in buffer string.
        ss.str(input); // send buffer to stream to tokenize.
        ss >> command; //send first token to check if it's a command.
        comm = hashT.ECOM(command);

        switch (comm) {
            case 1: //add
            {
                int value;
                if (!(ss >> value).fail()) //if it is a number
                {
                    if (value >= 0 && value < 10) { //check if it is between 0-9.

                        hashT.add(value);
                        ss.clear();
                        break;
                    } else {
                        cout << "Error! Value not between 0-9\n";
                        ss.clear();
                        break;
                    }
                } else {

                    cout << "Error! Input following command Add is not an integer.\n";
                    ss.clear();
                    break;

                }

            }//case 1
            case 2: //delete
            {
                int value;
                if (!(ss >> value).fail()) //if it is a number
                {
                    if (value >= 0 && value < 10) { //check if it is between 0-9.

                        hashT.del(value);
                        ss.clear();
                        break;
                    } else {
                        cout << "Error! Value not between 0-9\n";
                        ss.clear();
                        break;
                    }
                } else {
                    cout << "Error! Input following command Delete is not an integer.\n";
                    ss.clear();
                    break;

                }



            }//case 2
            case 3: //search
            {
                int value;
                if (!(ss >> value).fail()) //if it is a number
                {
                    if (value >= 0 && value < 10) { //check if it is between 0-9.

                        if (hashT.search(value)) cout << "true\n";
                        else cout << "false\n";
                        ss.clear();
                        break;
                    } else {
                        cout << "Error! Value not between 0-9\n";
                        ss.clear();
                        break;
                    }
                } else {
                    cout << "Error! Input following command Search is not an integer.\n";
                    ss.clear();
                    break;

                }





            }//case 3
            case 4: //show
            {
                hashT.show();
                ss.clear();
                break;
            }//case 4
            case 5: //quit
            {
                quit = true;
                ss.clear();
                break;

            }//case 5
            case -1:
            {
                cout << "Error! Invalid Command\n";
                ss.clear();
                break;
            }



        }


    }



    return 0;
}

