/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Person.h
 * Author: steph
 *
 * Created on January 25, 2017, 11:43 AM
 */

 #ifndef PERSON_H
 #define PERSON_H
 #include <iostream>
 #include <string>
 using namespace std;
 class Person {
   /*!
    * \private firstName , lastName,nationality
    */
 private:
   string firstName;
   string lastName;
   string nationality;
   /*!
    *  \public setters and getters
    */
 public:
   /*!
    *  \function sets the first name to the inputed value
    */
   void setFirstname(string f) { firstName = f; }
   /*!
    *  \function sets the last name to the inputed value
    */
   void setLastname(string l) { lastName = l; }
   /*!
    *  \function sets the nationality to the inputed value
    */
   void setNationality(string n) { nationality = n; }
   /*!
    *  \return returns the firstname as a string
    */
   string getFirstame() { return firstName; }
   /*!
    *  \return returns the last name as a string
    */
   string getLastname() { return lastName; }
   /*!
    *  \return the nationality as a string
    */
   string getNationality() { return nationality; }

   Person();
 };
 //  std::ostream &operator<<(std::ostream &out, const Person &p);
 #endif /* PERSON_H */
