
//! \file WordCList.cpp
//! \brief file for the WordCList subclass implemenation

#include <sstream>
#include <iostream>
#include "WordCList.h"
#include "LinkedList.h"

using namespace std;

//! \fn Constructor

WordCList::WordCList()
{}

//! \param temp the temporary holder of the word to be checked
//! \brief checks if a word is a repeat and incriments the count if it is
//! \return returns true if it finds a match and false otherwise
bool WordCList::incMatch(string temp)
{
    CListItr<WordData> lt(TheWords);
    if (!TheWords.empty())
    {

        for (lt.begin(); lt.more(); lt.next())
        {
            if ((*lt).getWord() == temp)
            {
                (*lt).incCount();
                return true;
            }
        }

    }
    
    
    return false;
    
}

//! \param inf the file to be read from
//! \brief applies polymorphism
void WordCList::parseIntoList(ifstream &inf)
{
    string temp;
    while (inf >> temp)
    {
            if (!incMatch(temp))
        {
            WordData wordInfo;
            wordInfo.setWordData(temp, 1);
            TheWords.orderedInsert(wordInfo);
        }
    }
}

//! \brief prints the Circular Linked List using and iterator
void WordCList::printIteratively()
{

    cout<<"--------------------------"<<endl;
  cout<<"|C Linked List  Iterative|"<<endl;
  cout<<"|Word         Occurences |"<<endl;  
  cout<<"--------------------------"<<endl;
  cout << " " << TheWords << endl;
}

//! \param passes an iterator for the circular linked list
//! \brief assists printRecursively in printing the list
void WordCList::printRecursivelyWorker(CListItr<WordData>& lt)
{
    lt.next();
    if (!lt.more())
    {
        cout << " " << lt.value() << endl;

        return;
    }

    cout << " "<< lt.value() << endl;
    printRecursivelyWorker(lt);
    
}

//! \brief prints the Circular Linked List Recursively
void WordCList::printRecursively()
{
    CListItr<WordData> lt(TheWords);
    lt.begin();

    cout<<"--------------------------"<<endl;
      cout<<"|C Linked List  Recursive|"<<endl;
      cout<<"|Word         Occurences |"<<endl;  
      cout<<"--------------------------"<<endl;
      cout << " "<< lt.value() << endl;
    printRecursivelyWorker(lt);
}