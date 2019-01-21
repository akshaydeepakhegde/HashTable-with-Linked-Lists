// Name: Akshay Deepak Hegde
// USC NetID: hegdeaks
// CSCI 455 PA5
// Fall 2018

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>

void commands();

using namespace std;

int main(int argc, char * argv[]) {

   // gets the hash table size from the command line

   int hashSize = Table::HASH_SIZE;

   Table * grades;  // Table is dynamically allocated below, so we can call
   // different constructors depending on input from the user.

   if (argc > 1) {
      hashSize = atoi(argv[1]);  // atoi converts c-string to int

      if (hashSize < 1) {
         cout << "Command line argument (hashSize) must be a positive number" 
              << endl;
         return 1;
      }

      grades = new Table(hashSize);

   }
   else {   // no command line args given -- use default table size
      grades = new Table();
   }


   grades->hashStats(cout);

  string cmd;
  string name;
  int score;

  while(1){
    cout << "cmd> ";
    cin >> cmd;
     
    if(cmd == "insert"){
      cin >> name;
      cin >> score;
      if(grades->insert(name, score)){
        cout << "name and score inserted into table." << endl;
      }
      else{
        cout << "name already present." << endl;
      }
    }
     
    else if(cmd == "change"){
      cin >> name;
      cin >> score;
      int *oldScore = grades->lookup(name);
      if(oldScore != NULL){
        *oldScore = score; 
        cout << "score is updated." << endl;
      }
      else{
        cout << "name not present." << endl;
      }
    }
     
    else if(cmd == "lookup"){
      cin >> name;
      int* score = grades->lookup(name);
      if(score == NULL){
        cout << "name not present." << endl;
      }
      else{
        cout << name << " : " << *score << endl;
      }
    }
     
    else if (cmd == "remove"){
      cin >> name;
      if(grades->remove(name)){
        cout << "removed" << endl;
      }
      else{
        cout << "name not present." << endl;
      }
    }
     
    else if (cmd == "print"){
      grades->printAll();
    }
     
    else if (cmd == "size"){
      cout << "Size : " << grades->numEntries() << endl;
    }
     
    else if (cmd == "stats"){
      grades->hashStats(cout);
    }
     
    else if (cmd == "help"){
      commands();
    }
     
    else if (cmd == "quit"){
      break;
    }
     
    else {
      cout << "ERROR: invalid command" << endl;
      commands();
    }
  }

   return 0;
}

void commands(){
  cout << "insert name score     --> Insert the name and score to the table." << endl;
  cout << "change name newscore  --> update the score for the name." << endl;
  cout << "lookup name           --> look up for the name and give his/her score." << endl;
  cout << "remove name           --> delete the entry of this name." << endl;
  cout << "print                 --> prints all entries of the table." << endl;
  cout << "size                  --> gives number of entries." << endl;
  cout << "stats                 --> displays statistics of the hash table at the point." << endl;
  cout << "help                  --> prints brief command summary." << endl;
  cout << "quit                  --> exits the program." << endl;
}