#ifndef ROTOR_H
#define ROTOR_H

#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<fstream>
#include<cctype>
#include "helper.h"
#include "errors.h"

//Rotor class encrypting all letters after the plugboard
//Inverted encryption after the reflector
//Rotates at predefined notches
class Rotor{
  int rot_configuration[ALPHABET];
  int notches[5];
  int reference_no = 0;
  Rotor * left = nullptr;
  Rotor * right = nullptr;
  int exit_code = 0;

  // Rotor constructor: checks inputs and fills rotor configuration and notches 
  Rotor(std::string const& call_string);

  //Recursive: The rotate function rotates the rotor it is called on.
  //If a notch is on top, it recursively rotates the rotor to the left as well. 
  void rotate();

  //Recursive: This function encrypts a digit on the rightmost rotor
  //recursively calls itself as long as more rotors exist to the left. 
  int encrypt_forward(int digit);

   //Recursive: Function encrypts a digit on the leftmost rotor after reflector
  //Recursively calls itself as long as more rotors exist to the right. 
  int encrypt_backwards(int digit);
  friend class Enigma;
};

#endif
