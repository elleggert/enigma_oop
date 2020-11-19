#include "helper.h"
#include "errors.h"

using namespace std;

void is_numeric(string const& digit_string, int& exit_code){
  for (int i = 0; i< int(digit_string.length()); i++){
    if (!isdigit(digit_string[i]))
      exit_code = NON_NUMERIC_CHARACTER;
  }
}
/*END OF FUNCTION*/
void int_input_in_range(int digit, int& exit_code){
  if (digit > 25 || digit < 0){
   exit_code = INVALID_INPUT_CHARACTER;
   return;
  }
 return;
}
/*END OF FUNCTION*/

void input_in_range(string const& digit_string, int& exit_code){
  int digit = stoi(digit_string);
  if (digit > 25 || digit < 0)
    exit_code = INVALID_INDEX;
}
/*END OF FUNCTION*/

bool is_repetitive(int count, int const configuration[26]){
  for (int i = count-1 ; i >=0 ; i--){
      if (configuration[i] == configuration[count])
	return false;
  }
  return true;
}
/*END OF FUNCTION*/

void error_handling(string const& call_string, int exit_code){
  switch (exit_code){
  case 1:
    cerr << call_string << "enigma plugboard-file reflector-file (<rotor-file>)* rotor-positions"<< endl;
    break;
  case 2:
    cerr << call_string << " is not a valid input character (input characters must be upper case letters A-Z)!" << endl;
    break;
  case 3:
    cerr << "Sorry, the file " << call_string << " contained a digit that exceeds the alphabetical range 0-26!" << endl;
    break;
  case 4:
    cerr << "Non-numeric character in configuration file: " << call_string << endl;
    break;
    case 5:
    cerr << "The plugboard configuration file " << call_string << " has an invalid input configuration!" << endl;
    break;
  case 6:
    cerr << "Incorrect number of parameters in plugboard file " << call_string << endl;
    break;
  case 7:
    cerr << "The rotor file " << call_string << " specified an invalid mapping" << endl;
    break;
  case 8:
    cerr << "The rotor file " << call_string << " did not specify a starting positions for all rotors" << endl;
    break;
  case 9:
    cerr << "The reflector configuration file " << call_string <<  " has an invalid input configuration" <<  endl;
    break;
  case 10:
    cerr << "Incorrect number of parameters in reflector file " << call_string << endl; 
    break;
  case 11:
    cerr << "The configuration file " << call_string << " could not be opened!" << endl;
    break;
  default:
    break;
  }
} 
/*END OF FUNCTION*/
