#ifndef ENIGMA_H
#define ENIGMA_H

#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<fstream>
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
  int set_rotor_starting_position(std::string const& call_string, int rotor_count);
  

 public:
  int exit_code = 0;
  Enigma(int argc, char ** argv);
  ~Enigma();
  void clear_rotor();

};



#endif
