#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<fstream>
#include<cctype>
#include "helper.h"

class Plugboard{
  int pb_configuration[26];
  int exit_code = 0;

  /*Constructor also checking the input validiry */
  Plugboard(std::string const& call_string);

  /*Encryption function*/
  int encrypt(int digit);
  
  friend class Enigma;
};


#endif
