/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Athlete.h
 * Author: steph
 *
 * Created on January 25, 2017, 11:43 AM
 */

 #ifndef ATHLETE_H
 #define ATHLETE_H
 #include "Person.h"
 #include <iostream>
 #include <string>
 using namespace std;
 /*!
  *  \extends Athlete extends Person
  */
 class Athlete : public Person {
   /*!
  *  \private distance
  */
 private:
   double distance;

 public:
   Athlete(){};
   /*!
  *  \function sets the distance to the inputed double
  */
   void setDistance(double d) { distance = d; }
   /*!
    *  \return returns the distance as a double
    */
   double getDistance() { return distance; }

 };
 /*!
  *  \overload overloads the  << sign to handle Athele objects
  */
 std::ostream &operator<<(std::ostream &out,  Athlete &a);
 #endif /* ATHLETE_H */
