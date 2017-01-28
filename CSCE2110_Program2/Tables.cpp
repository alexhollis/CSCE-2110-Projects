#include "Tables.h"
#include <cstdlib>
#include <algorithm>

using namespace std;

students::students(int idx, string namex, string last_namex) {
    id = idx;
    name = namex;
    last_name = last_namex;
}

grades::grades(int idx, string coursE, char gradex) {
    id = idx;
    course = coursE;
    grade = gradex;
}

studentTable::studentTable() {
};

gradeTable::gradeTable() {
};

int studentTable::Command(string str) {

    int val = -1; // defaulted to invalid command flag, until after checking to see if not junk.

    if (str == "add") val = 1;
    if (str == "delete") val = 2;
    if (str == "display") val = 3;
    if (str == "quit") val = 4;

    return val;
}

int studentTable::find(int ID) {

    int found = 0;

    if (!sList.empty()) {
        for (int i = 0; i < sList.size(); i++) {
            if (sList[i].id == ID) found = 1;

        }


    }

    return found;

}

int gradeTable::find(int ID) {

    int found = 0;

    if (!gList.empty()) {
        for (int i = 0; i < gList.size(); i++) {
            if (gList[i].id == ID) found = 1;

        }


    }

    return found;

}

void studentTable::add(int ID, string NAME, string LAST_NAME) {
    if (find(ID) == 0) // if value is not already in Tuple.
    {
        students temp(ID, NAME, LAST_NAME);
        sList.push_back(temp); // push new student on vector.

        // insert sort call here //
    } else cout << "Error! Student already in Table" << endl;



}

void gradeTable::add(int ID, string COURSE, char GRADE) {
    if (find(ID) == 0) // if value is not already in Tuple.
    {
        grades temp(ID, COURSE, GRADE);
        gList.push_back(temp); // push new student on vector.
        // insert sort call here //
    } else {
        string ccourse;


        for (int i = 0; i < gList.size(); i++) {
            if (gList[i].id == ID) {
                ccourse = gList[i].course;
            }
        }

        if (ccourse == COURSE) cout << "Error! Student already has a grade for " << COURSE << "." << endl; // check if there's a duplicate course.
        else {
            grades temp(ID, COURSE, GRADE);
            gList.push_back(temp);

        }


    }



}

void studentTable::sort() {

    int size = sList.size();

    if (size > 1) {

        int i, j;

        for (i = 0; i < size; i++) {

            for (j = 0; j < size - i - 1; j++) {

                if (sList[j].id > sList[j + 1].id) {
                    iter_swap(sList.begin() + j, sList.begin() + (j + 1));
                }


            }



        }
    }

}

void gradeTable::sort() {

    int size = gList.size();

    if (size > 1) {

        int i, j;

        for (i = 0; i < size; i++) {

            for (j = 0; j < (size - i - 1); j++) {

                if (gList[j].id > gList[j + 1].id) {
                    iter_swap(gList.begin() + j, gList.begin() + (j + 1));
                }
                if (gList[j].id == gList[j + 1].id) // if student is in grades more than once, do the following:
                {

                    if (gList[j].course > gList[j + 1].course) // check if courses for student are sorted already, if not:
                    {
                        iter_swap(gList.begin() + j, gList.begin() + (j + 1)); // swap the duplicates to make them be sorted alphabetically.

                    }

                }


            }



        }

    }
}

void studentTable::del(int ID, gradeTable *GT) { //pass the main grade table to edit if needed.
    if (find(ID)) //first check to see if student exists
    {
        sort();
        for (int i = 0; i < sList.size(); i++) //find position in vector of student
        {
            if (sList[i].id == ID) {
                sList.erase(sList.begin() + i); //remove student from vector.
                GT->del(ID, "DELETE");

            }
            if(i == (sList.size()-1) && sList.empty() != true ) i = 0;  //start from beginning to check for more grades to delete.
        }



    } else cout << "Error! Student not Found." << endl;


}

void gradeTable::del(int ID, string COURSE) {
    
    if(!gList.empty()){         //if grades not empty
    if (find(ID)) {
        
        sort();
        for (int i = 0; i < gList.size(); i++) {

            if (COURSE != "DELETE") { //only a grade is being deleted, student still in student table.
                if (gList[i].id == ID && gList[i].course == COURSE) {
                    gList.erase(gList.begin() + i);


                }

            }
            if (COURSE == "DELETE") //student was deleted from student table, need to delete all grades.
            {
                if (gList[i].id == ID) gList.erase(gList.begin() + i);
                if(gList.size() == 1 && gList[0].id == ID) gList.erase(gList.begin());

            }
        }


    } else cout << "Error! Grade for student in course provided not found." << endl;
    }
    if(gList.empty() && COURSE != "DELETE") cout << "Error! Grade Table is empty, nothing to delete." << endl;


}

void studentTable::disp() {
    int limit = (sList.size() - 1);
    sort(); // call just before printing to make sure table is sorted.

    if (sList.size()) { // not a empty table

        for (int i = 0; i < sList.size(); i++) {

            if (i < limit) // print data as "(...,...,...)-"
            {
                cout << "(" << sList[i].id << "," << sList[i].name << "," << sList[i].last_name << ")-";
            }
            if (i == limit) // print data as "(...,...,...) [newline]"
            {
                cout << "(" << sList[i].id << "," << sList[i].name << "," << sList[i].last_name << ")" << endl;

            }

        }

    } else cout << "empty table" << endl;

}

void gradeTable::disp() {
    int limit = (gList.size() - 1);
    sort(); // call just before printing to make sure table is sorted.

    if (gList.size()) { // not a empty table
        for (int i = 0; i < gList.size(); i++) {

            if (i < limit) // print data as "(...,...,...)-"
            {
                cout << "(" << gList[i].id << "," << gList[i].course << "," << gList[i].grade << ")-";
            }
            if (i == limit) // print data as "(...,...,...) [newline]"
            {
                cout << "(" << gList[i].id << "," << gList[i].course << "," << gList[i].grade << ")" << endl;

            }

        }

    } else cout << "empty table" << endl;

}
