#ifndef ENIGMA_H
#define ENIGMA_H

#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<fstream>
#include<cctype>
#include "plugboard.h"
#include "reflector.h"
#include "helper.h"
  
class Enigma{
  Plugboard * plugboard;
  Reflector * reflector;
  int rotor_count = 0; 

 public:
  int exit_code = 0;
  Enigma(int argc, char ** argv);

};



#endif
