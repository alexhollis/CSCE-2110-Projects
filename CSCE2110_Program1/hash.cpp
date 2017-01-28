//CSCE 2110 Program 1: Integer Hash Table Implementation with Closed Hashing. 
//Author: Alexander Hollis
//Contact: awh0045@unt.edu
//Collaboration Group (in class): Isaias Delgado, Michele Hindman, Josseline Rodriguez
//Files required: main.cpp, hash.h, hash.cpp
//Compiled on CSE Machine 01


#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "hash.h"

using namespace std;

Node::Node() {
}

Table::Table(int b) {

    buckets = b;
    hashmap = new Node* [buckets]; // create defined number of buckets of nodes. 




}//table

int Table::fetchID(int value) {

    int id = ((value * value) % buckets); // hash function = x^2 mod Buckets.




    return id;

}//fetchid

int Table::ECOM(string input) {
    int response = -1; //defaulted to -1 or command not found.
    transform(input.begin(), input.end(), input.begin(), ::tolower);

    if (input == "add") response = 1;
    if (input == "delete") response = 2;
    if (input == "search") response = 3;
    if (input == "show") response = 4;
    if (input == "quit") response = 5;
    return response;
}//ECOM

int Table::search(int val) {

    int id = fetchID(val);

    

    Node *temp = hashmap[id];



    if (temp == NULL) return 0;

    else {

        while (temp != NULL) {
            if (temp->data == val) {

                return 1;
            }
            temp = temp->next;
        }

        return 0;

    }



}//search

void Table::add(int val) {

    int id = fetchID(val);


    if (search(val) == 1) //if value is already in hash table
    {
        cout << "WARNING: duplicate input: " << val << "\n";
        return;
    } else {

        if (hashmap[id] == NULL) //no value stored in calculated bucket.
        {
            Node *root = new Node();
            root->data = val;
            root->next = NULL;
            hashmap[id] = root; //start new linked list
            return;
        }
        if (hashmap[id] != NULL) {
            Node *temp1, *temp2;
            temp1 = hashmap[id];
            while (temp1->next != NULL) {

                temp1 = temp1->next;

            }
            temp2 = new Node();
            temp2->data = val;
            temp2->next = NULL;
            temp1->next = new Node();
            temp1->next = temp2;
            return;
        }



    }



}//add

void Table::del(int val) {

    int id = fetchID(val);
    int exists = search(val); // see if the value exists.
    if (exists == 0) {
        cout << "WARNING: target value not found: " << val << "\n";
        return;
    } else {

        Node *del, *temp;

        temp = hashmap[id];

        if (temp->data == val) //if head of list contains the value.
        {

            del = temp;
            hashmap[id] = del->next;
            delete del;

            return;
        } else {

            del = temp->next;

            while (del != NULL) {
                if (del->data == val) {
                    temp->next = del->next;
                    delete del;

                    break;
                }
                temp = del;
                del = del->next;

            }



        }




    }



}//delete

void Table::show() {


    int limit = buckets;
    int i;
    Node *temp;

    for (i = 0; i < limit; i++) {

        temp = hashmap[i];
        if (temp == NULL) {

            if (i < limit - 1) cout << "()-"; //print all but last cell like this for blank sets.
            else cout << "()\n";
        } else {
            cout << "(";
            while (temp != NULL) {
                if (temp->next == NULL) {

                    cout << temp->data << ")";
                    if (i < limit - 1) cout << "-";
                    if (i == limit - 1)cout << "\n";
                } else cout << temp->data << ",";

                temp = temp->next;

            }



        }

    }





}//show
