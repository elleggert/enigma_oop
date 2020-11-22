#include "plugboard.h"
#include "errors.h"

using namespace std;
  
Plugboard::Plugboard(std::string const& call_string){
  int count = 0;
  string pb_digit_string;
  ifstream is_plugboard;
  
  is_plugboard.open(call_string, ios::in);
  if (!is_plugboard){
    exit_code = ERROR_OPENING_CONFIGURATION_FILE;
  }
 
  is_plugboard >> pb_digit_string;
  while (!exit_code && !is_plugboard.eof()){

    if (!exit_code)
      is_numeric(pb_digit_string, exit_code);
    if (!exit_code)
      input_in_range(pb_digit_string, exit_code);
    if (!exit_code)
      pb_configuration[count] = stoi(pb_digit_string);
    if (!exit_code){
      if (!is_repetitive(count, pb_configuration))
	exit_code = IMPOSSIBLE_PLUGBOARD_CONFIGURATION;
    }
    if (!exit_code)
      is_plugboard >> pb_digit_string;
    
    count++;
    if (!exit_code && count >= ALPHABET && !is_plugboard.eof())
	exit_code = INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS;
  }
  //SETTING A FLAG TO SIGNALISE END OF PLUGBOARD
  if (!exit_code && count < ALPHABET)
    pb_configuration[count] = -1;
  if (!exit_code && count % 2 == 1)
    exit_code = INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS;
  is_plugboard.close();
}

/*End of Function*/

int Plugboard::encrypt(int digit){
  int blocker = 0, remainder, i = 1;
  //Calculating how many plugboard connections were specified
  while (i >= 0 && blocker < ALPHABET){
    i = this->pb_configuration[blocker];
    blocker++;
  }

  for (int j = 0 ; j < blocker - 1 ; j++){
    if (this->pb_configuration[j] == digit){
      remainder = j % 2;
      if (!remainder)
	return (this->pb_configuration[j+1]);
      if (remainder)
	return (this->pb_configuration[j-1]);
    }
  }
  return digit;
}
/*End of Function*/
