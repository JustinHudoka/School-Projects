
//! \file WordCList.h
//! \brief header file for the WordCList subclass

#ifndef WordCList_H
#define WordCList_H
#include <assert.h>
#include <iostream>
#include "WordList.h"
#include "WordData.h"
#include "LinkedList.h"

using namespace std;

//! \class WordCList
//! \brief Circular linked list subclass of WordList
class WordCList : public WordList {
public:
    //! \fn Constructor
     WordCList();

    //! \param inf the file to be read from
    //! \brief applies polymorphism
    virtual void parseIntoList(ifstream &inf);

    //! \brief prints the Circular Linked List using and iterator
    virtual void printIteratively();

    //! \brief prints the Circular Linked List Recursively
    virtual void printRecursively();

private:

    //! Creates a circular linked list for TheWords
    CLinkedList<WordData> TheWords;

    //! \param temp the temporary holder of the word to be checked
    //! \brief checks if a word is a repeat and incriments the count if it is
    //! \return returns true if it finds a match and false otherwise
    bool incMatch(string temp);

    //! \param passes an iterator for the circular linked list
    //! \brief assists printRecursively in printing the list
    void printRecursivelyWorker(CListItr<WordData>& lt);
};
#endif