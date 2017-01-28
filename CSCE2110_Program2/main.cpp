/* 
 * File:   main.cpp
 * Author: Alex Hollis
 *
 * Created on November 12, 2014, 3:15 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include "Tables.h"
#include <sstream>
#include <algorithm>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    bool quit = false;
    studentTable students;
    gradeTable grades;
    string input, table, command; // input stores entire line of input; table stores the token of what should be students / grades; command - add, delete, display, quit.
    int comm; // command evaluated, use this integer to run through switch.

    istringstream ss; // use stream to tokenize input.

    while (quit == false) {

        cout << "tables> ";
        getline(cin, input);
        ss.str(input);
        ss >> table;
        transform(table.begin(), table.end(), table.begin(), ::tolower); // prevent capital letters from interfering with operations.
        
        if(table == "quit") {
            quit = true;
            continue;
        }
        if (table == "students") {

            ss >> command;
            comm = students.Command(command);

            switch (comm) {

                case 1: // add
                {
                    int id;
                    string name, last_name;

                    if (!(ss >> id).fail()) {
                        ss >> name;
                        ss >> last_name;
                        students.add(id, name, last_name);
                        students.sort();
                        ss.clear();
                        break;
                    } else cout << "Error! ID for student is not a number" << endl;
                    ss.clear();
                    break;

                }
                case 2: // delete
                {
                    int id;
                    if (!(ss >> id).fail()) {
                        students.del(id, &grades);
                        students.sort();
                        ss.clear();
                        break;
                    } else cout << "Error! ID given is not a number" << endl;
                    ss.clear();
                    break;

                }
                case 3: // display
                {
                    students.disp();
                    ss.clear();
                    break;

                }

                case -1: // invalid command
                {
                    ss.clear();
                    cout << "Error! Invalid Command" << endl;
                    break;
                }


            }


        }

        if (table == "grades") {


            ss >> command;
            comm = students.Command(command);

            switch (comm) {

                case 1: // add
                {
                    int id;
                    string course;
                    char grade;


                    if (!(ss >> id).fail()) {
                        ss >> course;
                        ss >> grade;
                        if (!isdigit(grade)) {
                            grades.add(id, course, grade);
                        } else cout << "Error! Invalid grade given, please use letters." << endl;
                        grades.sort();
                        ss.clear();
                        break;
                    } else cout << "Error! ID for student is not a number" << endl;
                    ss.clear();
                    break;

                }
                case 2: // delete
                {
                    int id;
                    string course;
                    if (!(ss >> id).fail()) {
                        ss >> course;
                        grades.del(id, course);
                        grades.sort();
                        ss.clear();
                        break;
                    } else cout << "Error! ID given is not a number" << endl;
                    ss.clear();
                    break;

                }
                case 3: // display
                {
                    grades.disp();
                    ss.clear();
                    break;

                }

                case -1: // invalid command
                {
                    ss.clear();
                    cout << "Error! Invalid Command" << endl;
                    break;
                }


            }





        }

        if (table != "students" && table != "grades") // invalid table specified.
        {
            comm == students.Command(table);
            if (comm == 4) quit = true;
            else {
            cout << "Error! Table specified is not valid, please use only students or grades." << endl;
            ss.clear();
            }
        }




    }



    return 0;
}

