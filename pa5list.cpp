// Name: Akshay Deepak Hegde
// USC NetID: hegdeaks
// CS 455 PA5
// Fall 2018

// pa5list.cpp
// a program to test the linked list code necessary for a hash table chain

// You are not required to submit this program for pa5.

// We gave you this starter file for it so you don't have to figure
// out the #include stuff.  The code that's being tested will be in
// listFuncs.cpp, which uses the header file listFuncs.h

// The pa5 Makefile includes a rule that compiles these two modules
// into one executable.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"


int main() {
   
    ListType list = NULL;

    insertList(list, "a", 1);
    //printList(list);
    insertList(list, "b", 2);
    //printList(list);
    insertList(list, "c", 3);
    //printList(list);
    insertList(list, "d", 4);
    //printList(list);
    insertList(list, "e", 5);
    printList(list);

    int * x = lookupList(list, "a");
    cout << *x << endl;

    bool y = removeList(list, "d");

    printList(list);
   
    cout << y << endl;



    return 0;
}
