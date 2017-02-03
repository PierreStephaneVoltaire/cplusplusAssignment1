/*
* To change this license header, choose License Headers in Project Properties.
* To change this template file, choose Tools | Templates
* and open the template in the editor.
*/

/*
* File:   main.cpp
* Author: steph
*
* Created on January 25, 2017, 11:43 AM
*/

#include "Athlete.h"
#include "Person.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
/*!
 *  \function converts a string to a double
 */
double StrToDbl(string s) {
	double d;
	stringstream ss(s); //turn the string into a stream
	ss >> d; //convert
	/*!
	 *  \return returns the double
	 */
	return d;
}
/*!
*  \function
*loadfile() will try to read the file and populate the vector with pointers to athelets
*/
vector<Athlete*> loadfile();
/*!
*  \function
*findJumper() will lok for all the athelets that performed better then the inputed integer
*/
void findJumper(double dist, std::vector<Athlete*> v);
/*!
*  \function
*deallocates memory
*/
void delocPointers(  vector<Athlete*> v);
/// main
int main(int argc, char const *argv[]) {
  ///creates a vector of pointers of atheles
  vector<Athlete*> v;
  /// then uses the loadfile() function to populate the vector vector
  v = loadfile();
  double distancequey = -1;
  do {
	  ///then asks for the user input
	  std::cout << "please enter the distance threshold:";
	  /// as a string
	  string input;
	  cin >> input;
	  ///then converts the input into a double
	   distancequey = StrToDbl(input);
	   cin.clear();
  } while (distancequey < 0);
	  
  ///then looks for a jumper that scored over the queried number using the findJumper() function
  findJumper(distancequey, v);
delocPointers(v);
  ///pauses the console for windows
  system("pause");
  return 0;
}
void delocPointers(vector<Athlete*> v){
for (int i = 0; i < v.size(); i++) {
  delete v[i]; //free memory

}


}
/*!
 *  \function reads the file and populates the vector
 */
vector<Athlete*> loadfile() {
  // vector of atheles
  vector<Athlete*> v;
  // ifstream to read the file
  ifstream myReadFile;
  myReadFile.open("jump.txt");
  /// if file oppened , read atheletes and put them into the vector
  if (myReadFile.is_open()) {
    std::cout << "file sucessfully oppened" << '\n';
    /// curent line
    string line;
    /// regexs for the words and digits
    /// get a combo of letters that has 0 or 1 underscore or/and 0 or 1 dash
    regex words("[[:alpha:]]+-*[[:alpha:]]*");
    /// get a floating point number
    regex digits("\\d+.*\\d+");
    ///skip first line
    int num = 0;
    /// read lines until end of file

    while (getline(myReadFile, line)) {
      if (num > 0) {
        /// make a new athele pointer
          Athlete* a = new Athlete();
        /// possible results
        smatch m;
        /// look for words
        regex_search(line, m, words);
        /// populate the athele with names and nationality
        a->setFirstname(m[0]);
        ///take everything that's not part of the result
        line = m.suffix();
        regex_search(line, m, words);
        a->setLastname(m[0]);
        ///take everything that's not part of the new result
        line = m.suffix();
        /// get the distance
        smatch numericResults;
        regex_search(line, numericResults, digits);
        /// get distance
        const string dist = numericResults[0].str();
          /// convert distance into a number
		double distance = StrToDbl(dist);
    ///set distance
        a->setDistance(distance);
        ///everything else is the nationality so set it to the object's pointer
        a->setNationality(numericResults.prefix());
        /// put the athlete pointer in the vector
        v.push_back(a);
      }
      num++;
    }
    /// send sucess message
    cout << "data loaded sucessfully" << '\n';
    /// return vector
    return v;
  }
  /*!
*  \else
*if the file could not be read
*/
  else {
    cout << "data could not be loaded" << '\n';
    return v;
  }
}
/*!
*  \brief
*find the athelets that have a distance inferior to the one queried by the user
*/

void findJumper(double dist, std::vector<Athlete*> v) {
    std::cout << "The athletes that exceeded "<<dist<<" m are:" << '\n';
    /*!
 *  \brief
*for loop to loop through the vector
 */
  for (int i = 0; i < v.size(); i++) {
    //if the distance is superior to the queried distance
    if (v[i]->getDistance() > dist) {
      cout << *v[i]<<endl;
    }
  }
}
