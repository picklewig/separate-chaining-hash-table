/**************
 * author: Isaac Shepherd
 * file: main.cpp
 * testbed for class Hashtable
 **************/

#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */
    
    // create your hash table object here
    Hashtable MyTable;
    // show it is empty by calling getCount and printTable
    cout << "Finding the number of entries in table..." << endl;
    MyTable.getCount();
    cout << "Printing table contents..." << endl;
    MyTable.printTable();
    // try and put ALL the test data into the table and show what happens
    cout << endl << "Adding entries now..." << endl;
    for(int index{0}; index < testdatasize; index++){
        if(MyTable.insertEntry(ids[index], &strs[index])){
            cout << ids[index] << " was added to table" << endl;
        }else{
            cout << ids[index] << " was NOT added to table" << endl;
        }
    }
    cout << "Displaying hashtable with new entries: " << endl << endl;
    MyTable.printTable();
    // continue using and testing your table, add and remove data,
    // do whatever it takes to full test your object and prove it
    // is robust and can handle all use cases.

    cout << endl << "Getting data strings from table..." << endl;
    for(int index{0}; index < testdatasize; index++){
        cout << "Data for list object " << ids[index] << " is: " << MyTable.getData(ids[index]) << endl;
    }

    cout << endl << "Entry count is currently: " << MyTable.getCount() << endl;

    cout << "Deleting all entries from table..." << endl;
    for(int index{0}; index < testdatasize; index++){
        if(MyTable.removeEntry(ids[index])){
            cout << "Entry id: " << ids[index] << " was found and deleted" << endl;
        }else{
            cout << "Entry id: " << ids[index] << " was NOT found and deleted" << endl;
        }
    }
    cout << endl << "Entry count is currently: " << MyTable.getCount() << endl;
    cout << "Printing table contents..." << endl;
    MyTable.printTable();

    cout << endl << "testing add entry exclusively on exception cases" << endl;
    cout << "Adding " << ids[testdatasize-3] << " to table...";
    if(MyTable.insertEntry(ids[testdatasize-3], &strs[testdatasize-3])){
        cout << " Success" << endl;
    }else{
        cout << " Failed" << endl;
    }
    cout << "Adding " << ids[testdatasize-2] << " to table...";
    if(MyTable.insertEntry(ids[testdatasize-2], &strs[testdatasize-2])){
        cout << " Success" << endl;
    }else{
        cout << " Failed" << endl;
    }
    cout << "Adding " << ids[testdatasize-1] << " to table...";
    if(MyTable.insertEntry(ids[testdatasize-1], &strs[testdatasize-1])){
        cout << " Success" << endl;
    }else{
        cout << " Failed" << endl;
    }
    return 0;
}
