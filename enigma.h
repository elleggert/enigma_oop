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
  
class Enigma{
  Plugboard * plugboard;
  Reflector * reflector;
  Rotor * leftmost_rotor;
  Rotor * rightmost_rotor;
  int rotor_count = 0;

  /*Function checking the validity of the rotor starting positions and assigns them to the rotors*/
  int set_rotors(std::string const& call_string, int rotor_count);  

 public:
  int exit_code = 0;

  /*Constructor of an enigma machine from the command line inputs. Also checks all command line inputs */
  Enigma(int argc, char ** argv);

  /*Destructor of every element of enigma*/
  ~Enigma();

  /*function to step through the rotor linkedlist and delete all nodes, part of destructor*/
  void clear_rotor();

  /*Function handling the encryption process*/
  int encryption(int letter);
};

#endif
