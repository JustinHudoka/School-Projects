/****************************************************************/
/*   Author:         Adam Tal                                   */
/*   Course:         CIS237 010                                 */
/*   Assignment:     #1                                         */
/*   Due Date:       January 30, 2009                           */
/*   Filename:       WordData.h                                 */
/*   Purpose:        The Only Addition i made to this file was  */ 
/*                   an overloading of the << operator.         */
/****************************************************************/

//! \file WordData.h
//! \brief header file for the WordData Class

#ifndef WORDDATA_H
#define WORDDATA_H
#include <iostream>
#include <string>

using namespace std;

//! \class WordData
//! \brief Word Data object class containing a word and its occurence rate
class WordData {

public:

        //! \fn Constructor
        WordData(string wrd = "", int cnt = 1);

        //! \brief Sets the word
        //! \param wrd the word to be set
        void setWord(string wrd);

        //! \brief Sets the occurence rate of the word
        //! \param cnt the number of times it occurs
        void setCount(int cnt);

        //! \brief Set Whole WordData Object
        //! \param wrd the word to be set
        //! \param cnt the number of times it occurs
        void setWordData(string,int);

        //! \brief Gets the current word of the WordData Object
        //! \return the word
        string getWord() const;
        //! \brief Gets the occurence rate of the word
        //! \return the count
        int getCount() const;

        //! \brief Increment the count of the word by 1
        //! \param inc is the amount to increment by and is set to 1
        void incCount(int inc = 1);

        //! \brief overload the < operator
        //! \param arg the argument to be tested against
        //! \return true if < arg
        bool operator<(WordData);
        //! \brief overload the <= operator
        //! \param arg the argument to be tested against
        //! \return true if <= arg
        bool operator<=(WordData);
        //! \brief overload the > operator
        //! \param arg the argument to be tested against
        //! \return true if > arg
        bool operator>(WordData);

        //! \brief overload the >= operator
        //! \param arg the argument to be tested against
        //! \return true if >= arg
        bool operator>=(WordData);


private:

        //! variables
        string word;
        int count;


};

//! \brief overload operator for output
//! \param output is the output stream
//! \param words is the WordData
//! \return the output stream
ostream &operator<<(ostream& output, const WordData &words);

#endif
