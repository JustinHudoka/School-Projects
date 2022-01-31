//! \file WordDataList.h
//! \brief Container of WordData objects. 
// Printing can be iterative or recursive. 


#ifndef WORDDATALIST_H
#define WORDDATALIST_H

#include <string>
#include "WordList.h"
#include "WordData.h"

using namespace std;

class WordDataList : public WordList {
public:

//! \fn Constructor
  WordDataList();

  // Put a string of strings into the list object
//! \param inf the file to be read from
//! \brief applies polymorphism
  virtual void parseIntoList(ifstream &inf);

  // Print the data iteratively
  //! \brief Print the data iteratively
  virtual void printIteratively();
  
  // Print the data recursively
  //! \brief Call worker function to print the data recursively
  virtual void printRecursively();
  
  // Print the data recursively with a pointer
  //! \brief Call worker function to print the data recursively
  virtual void printPtrRecursively();

private:
  WordData TheWords[10];
  int numWords;

  // Look for a match and increment if found
//! \param temp the temporary holder of the word to be checked
//! \brief checks if a word is a repeat and incriments the count if it is
//! \return returns true if it finds a match and false otherwise
  bool incMatch(string temp);
  
  // Function to actually perform recursive print
  //! \brief Print the data recursively
  //! \param numWords the number of words in the array
  void printRecursivelyWorker(int numWords);

  // Function to actually perform recursive print using pointer
  //! \brief Print the data recursively with a pointer
  //! \param numWords the number of words in the array
  void printPtrRecursivelyWorker(int numWords);


};
  
#endif
