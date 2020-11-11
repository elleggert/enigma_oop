#include "helper.h"

using namespace std;

void check_input_numerical(string const& digit_string, int& exit_code){
  for (int i = 0; i< int(digit_string.length()); i++){
    if (!isdigit(digit_string[i]))
      exit_code = 4;
  }
}

void check_input_in_range(string const& digit_string, int& exit_code){
  int digit = stoi(digit_string);
  if (digit > 25 || digit < 0)
    exit_code = 3;
}

void check_input_repetitive(int count, int const configuration[26], int& exit_code){
  for (int i = count-1 ; i >=0 ; i--){
      if (configuration[i] == configuration[count])
	exit_code = 9;
  }
}
