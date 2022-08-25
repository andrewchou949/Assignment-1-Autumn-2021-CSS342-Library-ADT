//
// Created by Andrew Chou on 10/10/2021.
//
// Library class demonstrating partially filled arrays
// Can add/remove books from library accordingly
  // if existing book on file, return false for add method
  // if no book left in list, return false for remove method
// findbooks in library
// List all book in the library method.


#include "library.h"
#include <string>
#include <iostream>

using namespace std;
// constructor with default name
// Pre: NA
// Post: New Object created.
Library::Library(const string &Name) {
  libName = Name;
  //No book in library initially
  currentBookCount = 0;
  //from header file, book array has been initialize to 100 (MAX value)
}

// destructor
// nothing on heap
// Pre: No check on memory leak in heap
// Post: guranteed object being destroy at the end of cycle.
Library::~Library() {
  // destructor
}

// true if book found in library
// Pre: NA
// Post: tell user if the book is in library or not,
    // true: if it is in library, false: if not
bool Library::isInLibrary(const string &BookName) const {
  if (currentBookCount == 0){
    return false;
  }
  for (int i = 0; i < currentBookCount; i++){
    if (books[i] == BookName){
      return true;
    }
  }
  return false;
}

// add a new book
// return true if successful, false if
// book already in library
// Pre: library book list remain the same
// Post: library book list increment by one number and one new book name added to the list.
bool Library::addBook(const string &BookName) {
  //if currentBookCount now is > than max, incorrect operation. (FALSE)
  if (currentBookCount > MAX){
    return false;
  }
  //Looping into the current book list now accoriding the book count right now (NOT MAX #)
  for (int i = 0; i < currentBookCount; i++){
    // If any book name in the list match with the name intended to be added now, return false
    // and end the loop --- NO BOOK WILL BE ADDED
    if (books[i] == BookName){
      return false;
    }
  }
  //Add new book into the list directly (Previous loop does not return false, means it never exist in list)
  //increment by one number each time being added.
  books[currentBookCount++] = BookName;
  return true;
}

// remove a book
// return true if successfully removed
// false if book not in library
// Pre: Library Book list remains the same
// Post: Library Book list count will decrease by one, the designated book name in the name is removed
bool Library::removeBook(const string &BookName) {
  //if no book in library, cannot remove anything (False)
  //Nothing below it will be executed
  if (currentBookCount == 0){
    return false;
  }
  //loop to get to position of the bookname from arg
  for (int i = 0; i < currentBookCount; i++){
    if (books[i] == BookName){
      //setting the designated position string to be the book name of the last item in array
      books[i] = books[currentBookCount-1];
      //Decrementing currentBookCount since we removed one book.
      currentBookCount--;
      //after removing successfully, it return true to the overall method; and simultaneously, end for loop
      return true;
    }
  }
  return false;
}

// list all books
// Pre: NA
// Post: print all the book name in library as a list to console 
void Library::listAllBooks() const {
  cout << "Library Name: " << libName << endl;
  //When there is no book in library
  if (currentBookCount == 0){
    cout << "There's no book in the Library." << endl;
  }
  //When there are books in the library
  else{
    cout << "Library Book List: \n";
    for (int i = 0; i < currentBookCount; i++){
      cout << books[i] << endl;
    }
  }
}

// Pre: NA
// Post: doing the printing of the library book list right now.
ostream &operator<<(ostream &Out, const Library &Lib) {
  Out << "Library Name: " << Lib.libName << endl;
  Out <<  "Library Book List: \n";
  for (int i = 0; i < Lib.currentBookCount; i++){
    Out << Lib.books[i] << endl;
  }
  return Out;
}