// Name: Akshay Deepak Hegde
// USC NetID: hegdeaks
// CSCI 455 PA5
// Fall 2018

// Table.cpp  Table class implementation


#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>

using namespace std;


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************

// constructor for default size table
Table::Table() {
   numOfEntries = 0;
   hashSize = HASH_SIZE;
   table = new ListType[hashSize];
   for (int i = 0; i < hashSize; i++) {
       table[i] = NULL;
   }
}


// constructor for specific size of table
Table::Table(unsigned int hSize) {
   numOfEntries = 0;
   hashSize = hSize;
   table = new ListType[hashSize];
   for (int i = 0; i < hashSize; i++) {
       table[i] = NULL;
   }
}


// to look up for a key in the table
int * Table::lookup(const string &key) {
   int bucket = hashCode(key);
   return lookupList(table[bucket], key);
}


// to remove a key from the table
bool Table::remove(const string &key) {
   int bucket = hashCode(key);
   if (removeList(table[bucket], key)) {
       numOfEntries--;
       return true;
   } else {
       return false;
   }
}


// to insert a key into the table
bool Table::insert(const string &key, int value) {
   int bucket = hashCode(key);
   if (insertList(table[bucket], key, value)) {
       numOfEntries++;
       return true;
   } else {
       return false;
   }
}


// to return the number of entries in the table
int Table::numEntries() const {
   return numOfEntries;
}


// to display all the elementts of the table
void Table::printAll() const {
   for (int i = 0; i < hashSize; i++) {
        printList(table[i]);
    }
}


// returns the numner of buckets
int Table::numOfBuckets() const {
   return hashSize;
}


// returns the number of non-empty buckets 
int Table::numOfNonEmptyBuckets() const {
   int num = 0;
   for (int i = 0; i < hashSize; i++) {
       if (table[i] != NULL) {
           num++;
       }
   }
   return num;
}


// returns the length of the longest chain
int Table::longestChain() const {
   int num = 0;
   for (int i = 0; i < hashSize; i++) {
       if (sizeList(table[i]) > num) {
           num = sizeList(table[i]);
       }
   }
   return num;
}


// to print the info of hash table
// diagnostic purposes only
void Table::hashStats(ostream &out) const {
   out << "number of buckets: " << numOfBuckets() << endl;
   out << "number of entries: " << numEntries() << endl;
   out << "number of non-empty buckets: " << numOfNonEmptyBuckets() << endl;
   out << "longest chain: " << longestChain() << endl;
}


