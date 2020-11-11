#ifndef HELPER_H
#define HELPER_H

#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<fstream>
#include<cctype>


void check_input_numerical(std::string const& digit_string, int& exit_code);

void check_input_in_range(std::string const& digit_string, int& exit_code);

void check_input_repetitive(int count, int const configuration[26], int& exit_code);

#endif
