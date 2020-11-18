#include "reflector.h"
#include "errors.h"

using namespace std;
  
Reflector::Reflector(string const& call_string){
  int count = 0;
  string rf_digit_string;
  ifstream is_reflector;
  
 
  is_reflector.open(call_string, ios::in);
  if (!is_reflector){
    exit_code = ERROR_OPENING_CONFIGURATION_FILE;
  }
 
  is_reflector >> rf_digit_string;
  while (!exit_code && !is_reflector.eof()){

    if (!exit_code)
      is_numeric(rf_digit_string, exit_code);
    if (!exit_code)
      input_in_range(rf_digit_string, exit_code);
    if (!exit_code)
      rf_configuration[count] = stoi(rf_digit_string);
    if (!exit_code){
      if (!is_repetitive(count, rf_configuration))
	  exit_code = INVALID_REFLECTOR_MAPPING;
    }
    if (!exit_code)
      is_reflector >> rf_digit_string;
    count++;
    if (count > 25 && !is_reflector.eof())
	exit_code = INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
  }
  if (!exit_code  && count < 26)
    exit_code = INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
  is_reflector.close();
}
/*End of Function*/

int Reflector::encrypt(int digit){
  int remainder;
  for (int i = 0 ; i < 26 ; i++){
    if (this->rf_configuration[i] == digit){
      remainder = i % 2;
      if (!remainder)
	return (this->rf_configuration[i+1]);
      if (remainder)
	return (this->rf_configuration[i-1]);
    }
  }
  return digit; //Return statement will never be reached, since the clauses above are MECE. Included to suppress warning. 
}

/*End of Function*/
