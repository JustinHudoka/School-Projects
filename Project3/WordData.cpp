/****************************************************************/
/*   Author:         Adam Tal                                   */
/*   Course:         CIS237 010                                 */
/*   Assignment:     #1                                         */
/*   Due Date:       January 30, 2009                           */
/*   Filename:       WordData.h                                 */
/*   Purpose:        The Only Addition i made to this file was  */ 
/*                   an overloading of the << operator.         */
/****************************************************************/
/***************************************
 *                                     *
 *    File:    WordData.cpp            *
 *    Author:  Michael Lanciano        *
 *    Date:    2/12/06                 *
 *    Purpose: Member implementation   *
 *             for Word Data class     *
 *                                     *
 ***************************************/

//! \file WordData.cpp
//! \brief file for the WordData Class object implementation

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "WordData.h"

using namespace std;

//! \fn Constructor
WordData::WordData(string wrd, int cnt)
{
        setWordData(wrd, cnt);
}

//! \brief Sets the word
//! \param wrd the word to be set
void WordData::setWord(string wrd)
{
        word = wrd;
}

//! \brief Sets the occurence rate of the word
//! \param cnt the number of times it occurs
void WordData::setCount(int cnt)
{
        count = cnt;
}

//! \brief Set Whole WordData Object
//! \param wrd the word to be set
//! \param cnt the number of times it occurs
void WordData::setWordData(string wrd, int cnt)
{
        setWord(wrd);
        setCount(cnt);
}

//! \brief Gets the current word of the WordData Object
//! \return the word
string WordData::getWord() const
{
        return(word);
}

//! \brief Gets the occurence rate of the word
//! \return the count
int WordData::getCount() const
{
        return(count);
}

//! \brief Increment the count of the word by 1
//! \param inc is the amount to increment by and is set to 1
void WordData::incCount(int inc)
{
        count+=inc;
}

//! \brief overload the < operator
//! \param arg the argument to be tested against
//! \return true if < arg
bool WordData::operator<(WordData arg)
{
        return(this->getWord() < arg.getWord());
}
//! \brief overload the <= operator
//! \param arg the argument to be tested against
//! \return true if <= arg
bool WordData::operator<=(WordData arg)
{
        return(this->getWord() <= arg.getWord());
}

//! \brief overload the > operator
//! \param arg the argument to be tested against
//! \return true if > arg
bool WordData::operator>(WordData arg)
{
        return(this->getWord() > arg.getWord());
}
//! \brief overload the >= operator
//! \param arg the argument to be tested against
//! \return true if >= arg
bool WordData::operator>=(WordData arg)
{
        return(this->getWord() >= arg.getWord());
}
//! \brief overload operator for output
//! \param output is the output stream
//! \param words is the WordData
//! \return the output stream
ostream &operator<<(ostream& output, const WordData &words)
{
  output<<words.getWord()<<"\t\t"<<words.getCount();
  return output;
}
