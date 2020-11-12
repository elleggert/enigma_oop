#include "rotor.h"

using namespace std;


Rotor::Rotor(string const& call_string){
  top_position = 0;
  exit_code = 0;
  left = nullptr;
  right = nullptr;

  int count = 0;
  string rot_digit_string;
  ifstream is_rotor;

    //Opening the file
  is_rotor.open(call_string, ios::in);
  if (!is_rotor)
    exit_code = 11;
  //Inserting the next digit from the file to fill the rotor configuration
  is_rotor >> rot_digit_string;
  while (exit_code == 0 && count <= 25){

    if (exit_code == 0)
      check_input_numerical(rot_digit_string, exit_code);
    if (exit_code == 0)
      check_input_in_range(rot_digit_string, exit_code);
    if (exit_code == 0)
      rot_configuration[count] = stoi(rot_digit_string);
    if (exit_code == 0 && !is_input_repetitive(count, rot_configuration))
      exit_code = 7;
    if (exit_code == 0)
      is_rotor >> rot_digit_string;
    count++;
  }
  // Filling the notches configuration
  if (exit_code == 0 && is_rotor){
    for (int j = 0;!is_rotor.eof(); j++){
    if (exit_code == 0)
      check_input_numerical(rot_digit_string, exit_code);
    if (exit_code == 0)
      check_input_in_range(rot_digit_string, exit_code);
    if (exit_code == 0){
      notches[j] = stoi(rot_digit_string);
      notches[j+1] = -1;
      is_rotor >> rot_digit_string;
    }
    }
  }
  is_rotor.close();
  cout << "Rotor" << endl;
  for (int l = 0 ; l <= 25 ; l++)
    cout << rot_configuration[l] << endl;
  cout << "Notches" << endl;
  for (int k = 0 ; k < 5 ; k++)
    cout << notches[k] << endl;
}


    
  
