#include "plugboard.h"

using namespace std;

  
Plugboard::Plugboard(std::string const& call_string){
  exit_code = 0;
  int count = 0;
  string pb_digit_string;
  ifstream is_plugboard;
  
  //Opening the file
  is_plugboard.open(call_string, ios::in);
  if (!is_plugboard){
    exit_code = 11;
  }
  //Inserting the next digit from the file
  is_plugboard >> pb_digit_string;
  while (exit_code == 0 && !is_plugboard.eof()){

    if (exit_code == 0)
      check_input_numerical(pb_digit_string, exit_code);
    if (exit_code == 0)
      check_input_in_range(pb_digit_string, exit_code);
    if (exit_code == 0)
      pb_configuration[count] = stoi(pb_digit_string);
    if (exit_code == 0){
      if (!is_input_repetitive(count, pb_configuration))
	exit_code = 5;
    }
    if (exit_code == 0)
      is_plugboard >> pb_digit_string;
    
    count++;
  }
  pb_configuration[count] = -1;
  if (exit_code == 0 && count % 2 == 1)
    exit_code = 6;
  
  is_plugboard.close();
  
  cout << "Plugboard" << endl;
  for (int j = 0 ; j < 26 ; j++)
    cout << pb_configuration[j] << endl;
}


int Plugboard::encrypt(int digit){
  int blocker = 0, remainder, i = 1;
  while (i > 0){
    i = this->pb_configuration[blocker];
    blocker++;
  }

  for (int j = 0 ; j < blocker - 1 ; j++){
    if (this->pb_configuration[j] == digit){
      remainder = j % 2;
      if (remainder == 0)
	return (this->pb_configuration[j+1]);
      if (remainder == 1)
	return (this->pb_configuration[j-1]);
    }
  }
  return digit;
}

      
