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
        table[row]->data.information = "";
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

string Hashtable::getData(int id){
    string foundData = "";
    Data emptyStruct;
    int row = hash(id);
    if(id > 0 and table[row]->getNode(id, &emptyStruct)){//needs validation parameter because getnode doesnt check
        foundData = emptyStruct.data;
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

bool Hashtable::insertEntry(int id, string* information){
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

void Hashtable::printTable(){
    for(int row{0}; row < HASHTABLESIZE; row++){
        table[row]->printList();
    }
}

bool Hashtable::removeEntry(int id){
    bool removed = false;
    int row = hash(id);
    if(id > 0 and table[row]->deleteNode(id)){ //needs validation parameter because deletenode doesnt check
        count--;
        removed = true;
    }
    return removed;
}