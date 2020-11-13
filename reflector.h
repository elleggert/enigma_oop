#ifndef REFLECTOR_H
#define REFLECTOR_H

#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<fstream>
#include<cctype>
#include "helper.h"

class Reflector{
  int rf_configuration[26];

 public:
  int exit_code = 0;
  Reflector(std::string const& call_string);
  int encrypt(int digit);
};


#endif
