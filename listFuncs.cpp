// Name: Akshay Deepak Hegde
// USC NetID: hegdeaks
// CSCI 455 PA5
// Fall 2018


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
   key = theKey;
   value = theValue;
   next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
   key = theKey;
   value = theValue;
   next = n;
}




//*************************************************************************
// put the function definitions for your list functions below



// gives the size of the list
int sizeList(ListType list) {
	int sizeL = 0;
    ListType p = list;
    while (p != NULL) {
        sizeL++;
        p = p->next;
    }
    return sizeL;
}


// prints all the elements of the list
void printList(ListType list) {
    ListType p = list;
    while (p != NULL) {
        cout << p->key << " " << p->value << endl;
        p = p->next;
    }
}


// looks for a specific target in the specific list
int *lookupList(ListType list, string target) {
    ListType p = list;
    while (p != NULL) {
        if (p->key == target) {
            return &(p->value);
        }
        p = p->next;
    }
    return NULL;
}


// to check whether the list contains a key
bool containsKeyList(ListType list, string target) {
    ListType p = list;
    while (p != NULL) {
        if (p->key == target) {
            return true;
        }
        p = p->next;
    }
    return false;
}


// to insert a pair(key and value) into a specific list
bool insertList(ListType &list, string target, int value) {
    if (containsKeyList(list, target)) {
        return false;
    }

    if (list == NULL) {
        list = new Node(target, value);
        return true;
    }

    ListType p = list;

    while (p->next != NULL) {
        p = p->next;
    }
    ListType addp = new Node(target, value);
    p->next = addp;
    return true;
}


// to remove a specific target from the specific list
bool removeList(ListType &list, string target) {	
    if(list == NULL){
        cout << "It's an empty list!" << endl;
        return false;
    }
    
    ListType node = list;
    ListType pre = NULL;
    if(node -> key == target){
        ListType p = list;
        list = p -> next;
        delete p;
        return true;
    }
    
    while(node != NULL){
        if(node -> key == target){
            pre -> next = node -> next;
            delete node;
            return true;
        }
        pre = node;
        node = node -> next;
    }
    return false;
}
