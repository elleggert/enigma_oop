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
    return;
  }
  //Inserting the next digit from the file
  is_plugboard >> pb_digit_string;
  while (exit_code == 0 && !is_plugboard.eof()){

    check_input_numerical(pb_digit_string, exit_code);
    
    check_input_in_range(pb_digit_string, exit_code);

    pb_configuration[count] = stoi(pb_digit_string);

    check_input_repetitive(count, pb_configuration, exit_code);

    is_plugboard >> pb_digit_string;

    count++;
  }
  if (exit_code == 0 && count % 2 == 1)
    exit_code = 6;
  pb_configuration[count] = -1;

  is_plugboard.close();

  cout << "Plugboard" << endl;
  for (int j = 0 ; j < 26 ; j++)
    cout << pb_configuration[j] << endl;
}
