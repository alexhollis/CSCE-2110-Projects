/* 
 * File:   Tables.h
 * Author: Alex Hollis
 *
 * Created on November 12, 2014, 3:28 PM
 */

#ifndef TABLES_H
#define	TABLES_H

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class students {
public:
    int id;
    string name;
    string last_name;
    students(int, string, string);


};

class grades {
public:
    int id;
    string course;
    char grade;
    grades(int, string, char);

};

class gradeTable // store Tuples of Grades for students.
{
public:
    vector<grades> gList;

    gradeTable(); // constructor for grade table.

    void add(int, string, char);
    void del(int, string); // delete grade by id with respect to course.
    void disp(); // prints out entire table.
    int find(int);
    friend class grades;
    void sort();
};

class studentTable // stores Tuples of Students.
{
public:
    vector<students> sList;

    studentTable(); //constructor for student table.
    friend class gradeTable;
    void add(int, string, string);
    void del(int,gradeTable* ); // delete student by id.
    void disp(); // prints out entire table.
    int find(int);
    int Command(string);
    friend class students;
    
    void sort();
};










#endif	/* TABLES_H */

