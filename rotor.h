#ifndef ROTOR_H
#define ROTOR_H

#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<fstream>
#include<cctype>
#include "helper.h"

class Rotor{
  int rot_configuration[26];
  int notches[5];
  
 public:
  int top_position = 0;
  Rotor * left = nullptr;
  Rotor * right = nullptr;
  int exit_code = 0;
  Rotor(std::string const& call_string);
};
  

#endif
