//CSCE 2110 Program 1: Integer Hash Table Implementation with Closed Hashing. 
//Author: Alexander Hollis
//Contact: awh0045@unt.edu
//Collaboration Group (in class): Isaias Delgado, Michele Hindman, Josseline Rodriguez
//Files required: main.cpp, hash.h, hash.cpp
//Compiled on CSE Machine 01

#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

class Node {
public:

    int data;
    Node *next;

    Node();


};

class Table {
private:
    int buckets;

public:
    Node** hashmap;

    Table(int buckets);
    void add(int);
    void del(int);
    int search(int); // will print true or false in the function itself.
    void show(); // output: (1,2,3)-(4,5,6)-...(x,y,z) for buckets 1-7.
    int fetchID(int); // calculate hash id using hash formula.
    int ECOM(string);
};









