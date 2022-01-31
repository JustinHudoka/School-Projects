
//! \file WordVectorList.cpp
//! \brief file for the WordVectorList subclass implemenation

#include <sstream>
#include <iostream>
#include <algorithm>
#include "WordVectorList.h"

using namespace std;
//! \fn Constructor
WordVectorList::WordVectorList()
{numWords = 0;}
//! \param temp the temporary holder of the word to be checked
//! \brief checks if a word is a repeat and incriments the count if it is
//! \return returns true if it finds a match and false otherwise
bool WordVectorList::incMatch(string temp)
{
    for(int i=0; i < TheWords.size(); i++)
    {
        WordData wordInfo = TheWords.at(i);
        if (temp == wordInfo.getWord())
        {
            wordInfo.setCount(wordInfo.getCount()+1);
            TheWords.at(i) = wordInfo;
            return true;
        }
    }

    return false;
}
//! \param inf the file to be read from
//! \brief applies polymorphism
void WordVectorList::parseIntoList(ifstream &inf)
{
    string temp;
    while (inf >> temp)
    if (!incMatch(temp))
    {
        WordData wordInfo;
        wordInfo.setWordData( temp, 1);
        TheWords.push_back(wordInfo);
        
    }
    sort(TheWords.begin(), TheWords.end());
    numWords = TheWords.size();
}
//! \brief prints the vector List using and iterator
void WordVectorList::printIteratively()
{
    vector<WordData>::iterator it = TheWords.begin();
    cout<<"--------------------------"<<endl;
  cout<<"|Object  Vector Iterative|"<<endl;
  cout<<"|Word         Occurences |"<<endl;  
  cout<<"--------------------------"<<endl;
  for(it; it<TheWords.end(); it++)
    cout<<" "<< *it <<endl;
}
//! \param numWords the size of the vector
//! \brief assists printRecursively in printing the list
void WordVectorList::printRecursivelyWorker(int numWords)
{
if (numWords==1) {
      cout<<"--------------------------"<<endl;
      cout<<"|Object  Vector Recursive|"<<endl;
      cout<<"|Word         Occurences |"<<endl;  
      cout<<"--------------------------"<<endl;
      cout<<" "<<TheWords.at(numWords-1)<<endl;
      return;
    }
    printRecursivelyWorker(numWords-1);
    cout<<" "<<TheWords.at(numWords-1)<<endl;
}
//! \brief prints the vector List Recursively
void WordVectorList::printRecursively()
{printRecursivelyWorker(numWords);}