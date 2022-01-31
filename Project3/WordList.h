//! \file WordList.h
//! \brief Abstract base class for containers of word data
// Known subclasses:
//      WordDataList
// Coming soon: ParallelArrayWordList, WordVectorList, ...

#ifndef WORDLIST_H
#define WORDLIST_H

#include <fstream>
#include <string>

using namespace std;

//! \class WordList
//! \brief base class for containers of word data

class WordList {
public:

  // Place the line of text into the data structure

  //! \param inf the file to be read from
    //! \brief applies polymorphism
  virtual void parseIntoList(ifstream &inf)=0;

  // Print the data iteratively
  //! \brief prints the Circular Linked List using and iterator
  virtual void printIteratively()=0;
  
  // Print the data recursively
  //! \brief prints the Circular Linked List Recursively
  virtual void printRecursively()=0;
  
  // Print the data recursively with a pointer
  //! \brief Call worker function to print the data recursively
  virtual void printPtrRecursively() {}   // not pure virtual; why?

    
};
  
#endif
