
//! \file WordVectorList.h
//! \brief header file for the WordVectorList subclass

#ifndef WORDVECTORLIST_H
#define WORDVECTORLIST_H

#include <vector>
#include "WordList.h"
#include "WordData.h"

using namespace std;

//! \class WordVectorList
//! \brief vector list subclass of WordList
class WordVectorList : public WordList {
public:
//! \fn Constructor
    WordVectorList();
//! \param inf the file to be read from
    //! \brief applies polymorphism
    virtual void parseIntoList(ifstream &inf);
//! \brief prints the vector List using and iterator
    virtual void printIteratively();
//! \brief prints the vector List Recursively
    virtual void printRecursively();

private:
    vector<WordData> TheWords;

    int numWords;

//! \param temp the temporary holder of the word to be checked
    //! \brief checks if a word is a repeat and incriments the count if it is
    //! \return returns true if it finds a match and false otherwise
    bool incMatch(string temp);
//! \param numWords the size of the vector
//! \briefassists printRecursively in printing the list
    void printRecursivelyWorker(int numWords);

};

#endif