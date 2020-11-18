#ifndef ROTOR_H
#define ROTOR_H

#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<fstream>
#include<cctype>
#include "helper.h"

class Rotor{
  int rot_configuration[26];
  int notches[5];
  int reference_no = 0;
  Rotor * left = nullptr;
  Rotor * right = nullptr;
  int exit_code = 0;

  // The rotor constructor will check all inputs and fill the rotor configuration and notches arrays
  Rotor(std::string const& call_string);

  //Recursive: The rotate function rotates the rotor it is called on. If a notch is on top, it recursively rotates the rotor to the left as well. 
  void rotate();

  //Recursive: This function encrypts a digit on the rightmost rotor, and recursively calls itself as long as more rotors exist to the left. 
  int encrypt_forward(int digit);

   //Recursive: This function encrypts a digit on the leftmost rotor after the reflector, and recursively calls itself as long as more rotors exist to the right. 
  int encrypt_backwards(int digit);
  friend class Enigma;
};

#endif
