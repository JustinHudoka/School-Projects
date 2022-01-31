//! \file WordDataList.cpp
//! \brief Container of WordData objects 
//   Implementations of member functions including inherited pure virtual fns.

#include <sstream>
#include <iostream>
#include "WordDataList.h"

using namespace std;

//! \fn Constructor
  WordDataList::WordDataList()
  { numWords=0; }

//! \param temp the temporary holder of the word to be checked
//! \brief checks if a word is a repeat and incriments the count if it is
//! \return returns true if it finds a match and false otherwise
  bool WordDataList::incMatch(string temp)
  { for(int i=0; i<numWords; i++) {
      if (temp==TheWords[i].getWord()) {
        TheWords[i].incCount();
        return true;
      }
    }  
    return false;
  }

//! \param inf the file to be read from
//! \brief applies polymorphism
  void WordDataList::parseIntoList(ifstream &inf)
  { string temp;
    while (inf >> temp) 
      if (!incMatch(temp) && numWords < 10) {
          TheWords[numWords].setWord(temp);
          TheWords[numWords++].setCount(1);
      }
  }

  //! \brief Print the data iteratively
  void WordDataList::printIteratively()
//  void printObjectArrayIterator(WordData TheWords[], int numWords)
{
  cout<<"--------------------------"<<endl;
  cout<<"|Object  Array  Iterative|"<<endl;
  cout<<"|Word         Occurences |"<<endl;  
  cout<<"--------------------------"<<endl;
  for(int i=0; i<numWords; i++)
    cout<<" "<<TheWords[i]<<endl;
}

  
  //! \brief Print the data recursively
  //! \param numWords the number of words in the array
  void WordDataList::printRecursivelyWorker(int numWords)
  //void printObjectArrayRecursive(WordData TheWords[], int numWords)
  {if (numWords==1) {
      cout<<"--------------------------"<<endl;
      cout<<"|Object  Array  Recursive|"<<endl;
      cout<<"|Word         Occurences |"<<endl;  
      cout<<"--------------------------"<<endl;
      cout<<" "<<TheWords[numWords-1]<<endl;
      return;
    }
    printRecursivelyWorker(numWords-1);
    cout<<" "<<TheWords[numWords-1]<<endl;
  }

  //! \brief Call worker function to print the data recursively
  void WordDataList::printRecursively()
  {  printRecursivelyWorker(numWords); }


  //! \brief Print the data recursively with a pointer
  //! \param numWords the number of words in the array
  void WordDataList::printPtrRecursivelyWorker(int numWords)
  //void printObjectArrayPointerRecursive(WordData* TheWords, int numWords)
  {if (!numWords)
    { cout<<"--------------------------"<<endl;
      cout<<"|Object  Array  Pointer  |"<<endl;
      cout<<"|Word         Occurences |"<<endl;  
      cout<<"--------------------------"<<endl;
      return;
    }
    printPtrRecursivelyWorker(numWords-1);
    cout<<" "<<*(TheWords+(numWords-1))<<endl;
  }

  //! \brief Call worker function to print the data recursively
  void WordDataList::printPtrRecursively()
  { printPtrRecursivelyWorker(numWords); }
