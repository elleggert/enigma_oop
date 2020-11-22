#ifndef REFLECTOR_H
#define REFLECTOR_H

#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<cctype>
#include "helper.h"
#include "errors.h"

class Reflector{
  int rf_configuration[ALPHABET];
  int exit_code = 0;

  /*Constructor for the reflector, called when enigma is created*/
  Reflector(std::string const& call_string);
  
  int encrypt(int digit);
  friend class Enigma;
};


#endif
