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

bool is_input_repetitive(int count, int const configuration[26]){
  for (int i = count-1 ; i >=0 ; i--){
      if (configuration[i] == configuration[count])
	return false;
  }
  return true;
}

void error_handling(string const& call_string, int exit_code){
  switch (exit_code){
  case 0:
    cerr << "Success! Enigma was configured successfully." << endl;
    break;
  case 1:
    cerr << "The Command Line Call of the Enigma Machine has not specified a sufficient amount of parameters." << endl;
    break;
  case 2:
    cerr << "You have specified an invalid input character. Inputs need to be uppercase letters from A to Z!" << endl;
    break;
  case 3:
    cerr << "Sorry, the file " << call_string << " contained a digit that exceeds the alphabetical range 0-26!" << endl;
    break;
  case 4:
    cerr << "Sorry, the file " << call_string << " contained a non-numerical character!" << endl;
    break;
    case 5:
    cerr << "Sorry, the plugboard configuration file " << call_string << " has an invalid input configuration!" << endl;
    break;
  case 6:
    cerr << "Sorry, the plugboard configuration file " << call_string << " speficied an uneven number of connections!" << endl;
    break;
  case 7:
    cerr << "Sorry, the rotor configuration file " << call_string << " has an invalid input configuration!" << endl;
    break;
  case 8:
    cerr << "Sorry, the rotor position configuration file " << call_string << " did not specify exactly one starting position for every rotor!" << endl;
    break;
  case 9:
    cerr << "Sorry, the reflector configuration file " << call_string << " has an invalid input configuration!" << endl;
    break;
  case 10:
    cerr << "Sorry, the reflector configuration file " << call_string << " did not spefify exactly 13 pairs!" << endl;
    break;
  case 11:
    cerr << "Sorry, the configuration file " << call_string << " could not be opened!" << endl;
    break;
  default:
    break;
  }
} 
