/**************
 * author: Isaac Shepherd
 * file: hashtable.h
 * holds class prototype and constants used in hastable.cpp.
 **************/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "string"
#include <iostream>

#define HASHTABLESIZE 15

using std::cout;
using std::endl;
using std::string;

struct Data {
    int id;
    string data;
};

struct Node {
    Data data;
    Node *next;
};

class Hashtable{
    public:
        Hashtable();
        ~Hashtable();

        bool addEntry(int, string*);
        string getEntry(int);
        bool removeEntry(int);
        int getCount();
        void displayTable();
    private:
        Node* createNode(int, string*);
        int hash(int);
        int count;
        Node* table[HASHTABLESIZE];
};

#endif