#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<fstream>
#include<cctype>
#include "helper.h"
#include "errors.h"

//Plugboard class encrypting letters according to pre-specified connections 
class Plugboard{
  int pb_configuration[ALPHABET];
  int exit_code = 0;

  /*Constructor also checking the input validiry */
  Plugboard(std::string const& call_string);

  /*Encryption function*/
  int encrypt(int digit);
  
  friend class Enigma;
};


#endif
