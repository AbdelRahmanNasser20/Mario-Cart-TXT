/***********************************************************
 ** File:    Banana.h
 ** Project: UMBC Mario Kart
 ** Author:  Jeremy Dixon
 ** Date     11/1/2021
 ** Section: N/A
 ** This file contains the header file of the Banana class
 **********************************************************/
#ifndef BANANA_H
#define BANANA_H
#include "Obstacle.h"
#include <string>

//OPTIONAL CLASS FOR EXTRA CREDIT
//DO NOT EDIT UNTIL YOU HAVE COMPLETED THE BASE PROJECT!

class Banana: public Obstacle {
public:
  // Name: Banana (Default constructor)
  // Desc: Creates a banana
  // Preconditions:  Uses Obstacle default constructor
  // Postconditions: A banana is created.
  Banana();
  
  // Name: ~Banana
  // Desc: Destructor for banana
  // Preconditions:  Banana exists
  // Postconditions: Banana is cleared
  ~Banana();

  // Name: GetType
  // Desc: Returns the name of the subtype (Banana)
  // Preconditions:  None
  // Postconditions: Returns string name of the subtype (Banana)
  virtual string GetType();
  
  // Name: overloaded operator<<
  // Desc: Allows Banana objects to be outputted
  // Preconditions:  None
  // Postconditions: Outputs banana description
  virtual ostream& operator<<(ostream&);

};

#endif 
