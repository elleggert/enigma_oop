#ifndef ENIGMA_H
#define ENIGMA_H

#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<cctype>
#include "plugboard.h"
#include "reflector.h"
#include "rotor.h"
#include "helper.h"
#include "errors.h"

//Class combining all elements and behaviour of enigma machine
// Consists of rotor linked list, plugboard and reflector
class Enigma{
  Plugboard * plugboard;
  Reflector * reflector;
  Rotor * leftmost_rotor;
  Rotor * rightmost_rotor;
  int rotor_count = 0;
  
  /*Checking validity of rotor starting positions and assigns them to rotors*/
  int set_rotors(std::string const& call_string, int rotor_count);
  
 public:
  int exit_code = NO_ERROR;
  
  /*Constructor of an enigma machine. Also checks all command line inputs */
  Enigma(int argc, char ** argv);
  
  /*Destructor of every element of enigma*/
  ~Enigma();
  
  /*Deleting all nodes in rotor linkedlist, called by enigma destructor*/
  void clear_rotor();
  
  /*Function handling the encryption process*/
  int encryption(int letter);
};

#endif
