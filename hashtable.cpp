/**************
 * author: Isaac Shepherd
 * file: hashtable.cpp
 * defines methods, contructor, and destructor of class prototype in hashtable.h
 **************/

#include "hashtable.h"

int Hashtable::hash(int id){ //hash ids to find which location in array to add to
    return id % HASHTABLESIZE;
}
Hashtable::Hashtable(){
    count = 0;
    for(int row{0}; row < HASHTABLESIZE; row++){
        table[row] = new Node;
        table[row]->data.id = 0;
        table[row]->data.data = "";
    }
}

Hashtable::~Hashtable(){
    for(int row{0}; row < HASHTABLESIZE; row++){
        delete table[row];//upon deletion linklist object should call its clearlist method
    }
}

int Hashtable::getCount(){
    return count;
}

string Hashtable::getEntry(int id){
    string foundData = "";
    int row = hash(id);
    if(id > 0){
        Node* current = table[row];
        while(current->next != NULL and id != current->data.id){
            current = current->next;
        }
        if(id == current->data.id){
            foundData = current->data.data;
        }
    }
    return foundData;
}

Node* Hashtable::createNode(int id, string* information){
    Node *newNode = new Node;
    newNode->data.id = id;
    newNode->data.data = *information;
    newNode->next = NULL;
    return newNode;
}

bool Hashtable::addEntry(int id, string* information){
    bool inserted = false;
    int row = hash(id); //derives row to set value in
    if(id > 0 and *information != ""){
        Node* current = table[row];
        if(current->data.id == 0){
            table[row] = createNode(id, information);
            inserted = true;
            count++;
        }
        else{
            while(current and current->next != NULL){
                current = current->next;
            }
            if(current->next == NULL){
                Node* insertNode = createNode(id, information);
                current->next = insertNode;
                inserted = true;
                count++;
            }
        }
    }
    return inserted;
}

void Hashtable::displayTable(){
    for(int row{0}; row < HASHTABLESIZE; row++){
        Node* current = table[row];
        int nodeNumber = 0;
        while(current){
            nodeNumber++
            cout << current->data.id;
            if(current->next != NULL){
                cout << " --> ";
            } else {
                cout << endl;
            }
            current = current->next;
        }
        if(nodeNumber == 0){
            cout << "EMPTY" << endl;
        }
    }
}

bool Hashtable::removeEntry(int id){
    bool removed = false;
    int row = hash(id);
    if(id > 0){
        Node* current = table[row];
        Node* previous;
        while(current and id != current->data.id){
            previous = current;
            current = current->next;
        }
        if(current and id == current->data.id){
            if(previous != NULL and current->next == NULL){
                previous->next = NULL;
            }
            else if(current->next != NULL and previous == NULL){
                table[row] = current->next;
            }
            else if(current->next != NULL and previous != NULL){
                previous->next = current->next;
            }
            delete current;
            removed = true;
            count--;
        }
    }
    return removed;
}