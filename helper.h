#ifndef HELPER_H
#define HELPER_H

#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<fstream>
#include<cctype>

//Function to check whether a string represents a number
void is_numeric(std::string const& digit_string, int& exit_code);

//Function to check whether a given string represents a number between 0 and 25
void input_in_range(std::string const& digit_string, int& exit_code);

//Function checking whether an integer input is between 0 and 25
void int_input_in_range(int digit, int& exit_code);

//Boolean function checking whether a digit appears twice in an array
bool is_repetitive(int count, int const configuration[26]);

//Function printing an informative error message to the error stream
void error_handling(std::string const& call_string, int exit_code);

#endif
