/****************************************************************/
/*   Author:         Dr. Spiegel (with thanks to Adam Tal)      */
/*   Course:         CIS237 310                                 */
/*   Filename:       app.cpp                                    */
/*   Purpose:        This Example inputs a string and demon-    */
/*                   strates how to store it using a subclass   */
/*                   of an abstract base class that incorporates*/
/*                   virtual functions to enable polymorphism   */
/*                   If a file name is                          */
/*                   input through the command line all of the  */
/*                   options will be done automatically for the */
/*                   first line of the file                     */
/****************************************************************/
//! \file app.cpp
//! \brief test driver for Project3

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include "WordList.h"
#include "WordDataList.h"
#include "WordVectorList.h"
#include "WordCList.h"
#include <chrono>
// #include "WordData.h"        app only knows about the lists!

using namespace std;

void displayMenu();
/*********************************************************************/
/*   Function Name: displayMenu()                                    */
/*                                                                   */
/*   Description: Displays the menu on the screen.                   */
/*********************************************************************/

void printEverything(ifstream &inf,WordList *TheList);
/*********************************************************************/
/*                                                                   */
/*   Function Name: printEverything                                  */
/*                                                                   */
/*   Description: Takes in a sentence and sends it through every     */
/*                parsing and printing function                      */
/*                                                                   */
/*   Parameters:  string sentence - sent to every function           */
/*                WordDataList TheList - The array of object         */
/*********************************************************************/


int main(int argc,char *argv[])
{ ifstream inf;
  WordList *TheList;
  if(argc>1) //if there was an input on the command line
    {
      inf.open(argv[1]); //try and open the file
      if (inf.fail())       //if the file does not open
        {                    //terminate
          cout<<"Sorry, the file failed to open."<<endl;
          return 0;
        }
      printEverything(inf,TheList);
      return 0;
    }

  char selection;
  string fileName;
  cout<<"Please enter a file name:"<<endl;
  getline(cin,fileName);
  inf.open(fileName.c_str());
  
  // TheList is a pointer to a WordList that is pointed at a WordList subclass
  
  using namespace std::chrono;

  while (true)
    {
      inf.clear();
      inf.seekg(0, ios::beg);
      displayMenu();
      cin>>selection;

      auto begin = std::chrono::high_resolution_clock::now();
      switch(selection)
        { case '1':
            TheList=new WordDataList;
            TheList->parseIntoList(inf);  // Apply polymorphism
            TheList->printIteratively();
            delete TheList;
            break;
          case '2':
            TheList=new WordDataList;
            TheList->parseIntoList(inf);  // Apply polymorphism
            TheList->printRecursively();
            delete TheList;
            break;
          case '3':
            TheList=new WordDataList;
            TheList->parseIntoList(inf);  // Apply polymorphism
            TheList->printPtrRecursively();
            delete TheList;
            break;
          case '4':
          TheList=new WordCList;
          TheList->parseIntoList(inf);
          TheList->printIteratively();
          delete TheList;
            break;
          case '5':
          TheList=new WordCList;
          TheList->parseIntoList(inf);
          TheList->printRecursively();
          delete TheList;
            break;
          case '6':
            TheList=new WordVectorList;
            TheList->parseIntoList(inf);
            TheList->printIteratively();
            delete TheList;
            break;
          case '7':
            TheList=new WordVectorList;
            TheList->parseIntoList(inf);
            TheList->printRecursively();
            delete TheList;
            break;
          case '8':
            cout<<"Goodbye"<<endl;
            return 0;
          default:
            cout<<"I cannot understand "<<selection<<".  Try again."<<endl;
            break;

            
        }

        auto end = high_resolution_clock::now();
        auto ticks = duration_cast<microseconds>(end-begin);
        cout << endl << "Selection " << selection <<" completed in " << ticks.count()<< " Microseconds" << endl;
    }
  
  return 0;
}

//! \brief prints out the menu
void displayMenu()
{
  cout<<endl;
  cout<<"How do you want to print your sentence elements?"<<endl;
  cout<<"------------------------------------------------"<<endl;
  cout<<"1. Object Array Iterative"<<endl;
  cout<<"2. Object Array Recursive"<<endl;
  cout<<"3. Object Array Pointer Recursive"<<endl;
  cout<<"4. Circular Linked List Iterative"<<endl;
  cout<<"5. Circular Linked List Recursive"<<endl;
  cout<<"6. Object Vector Iterative"<<endl;
  cout<<"7. Object Vector Recursive"<<endl;
  cout<<"8. Quit"<<endl;
}

//! \param inf the file to be read from
//! \param TheList a pointer to a WordList that is pointed at a WordList subclass
//! \brief Prints out all options
void printEverything(ifstream &inf,WordList *TheList)
{ 
  using namespace std::chrono;

  
  
  TheList=new WordDataList;
  auto aZero = std::chrono::high_resolution_clock::now();
  TheList->parseIntoList(inf);
  auto aOne = std::chrono::high_resolution_clock::now();
  TheList->printIteratively();
  auto aTwo = std::chrono::high_resolution_clock::now();
  TheList->printRecursively();
  auto aThree = std::chrono::high_resolution_clock::now();
  TheList->printPtrRecursively();
  auto aFour = std::chrono::high_resolution_clock::now();
  delete TheList;
  inf.clear();
  inf.seekg(0, ios::beg);
  TheList=new WordCList;
  auto cZero = std::chrono::high_resolution_clock::now();
  TheList->parseIntoList(inf);
  auto cOne = std::chrono::high_resolution_clock::now();
  TheList->printIteratively();
  auto cTwo = std::chrono::high_resolution_clock::now();
  TheList->printRecursively();
  auto cThree = std::chrono::high_resolution_clock::now();
  delete TheList;
  inf.clear();
  inf.seekg(0, ios::beg);
  TheList=new WordVectorList;
  auto vZero = std::chrono::high_resolution_clock::now();
  TheList->parseIntoList(inf);
  auto vOne = std::chrono::high_resolution_clock::now();
  TheList->printIteratively();
  auto vTwo = std::chrono::high_resolution_clock::now();
  TheList->printRecursively();
  auto vThree = std::chrono::high_resolution_clock::now();
  delete TheList;

  auto Parse = duration_cast<microseconds>(aOne-aZero);
  auto pOne = duration_cast<microseconds>(aTwo-aOne);
  auto pTwo = duration_cast<microseconds>(aThree-aTwo);
  auto pThree = duration_cast<microseconds>(aFour-aThree);
  cout << endl << "Array "<< endl << "Parse: " << Parse.count() << " Print It: " << pOne.count() << " Print Re: " << pTwo.count() <<" Print Ptr: " << pThree.count() << endl;

   Parse = duration_cast<microseconds>(cOne-cZero);
   pOne = duration_cast<microseconds>(cTwo-cOne);
   pTwo = duration_cast<microseconds>(cThree-cTwo);

  cout << endl << "Linked List "<< endl << "Parse: " << Parse.count() << " Print It: " << pOne.count() << " Print Re: " << pTwo.count() << endl;

  Parse = duration_cast<microseconds>(vOne-vZero);
   pOne = duration_cast<microseconds>(vTwo-vOne);
   pTwo = duration_cast<microseconds>(vThree-vTwo);

   cout << endl << "Vector "<< endl << "Parse: " << Parse.count() << " Print It: " << pOne.count() << " Print Re: " << pTwo.count() << endl;

}
