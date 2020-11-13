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

 public:
  int exit_code = 0;
  Plugboard(std::string const& call_string);
  int encrypt(int digit);
};


#endif
