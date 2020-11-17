#include "rotor.h"
#include "errors.h"

using namespace std;


Rotor::Rotor(string const& call_string){
  reference_no = 0;
  exit_code = 0;
  left = nullptr;
  right = nullptr;

  int count = 0;
  string rot_digit_string;
  ifstream is_rotor;

    //Opening the file
  is_rotor.open(call_string, ios::in);
  if (!is_rotor)
    exit_code = ERROR_OPENING_CONFIGURATION_FILE;
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
      exit_code = INVALID_ROTOR_MAPPING;
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

  /*
  cout << "Rotor" << endl;
  for (int l = 0 ; l <= 25 ; l++)
    cout << rot_configuration[l] << endl;
  cout << "Notches" << endl;
  for (int k = 0 ; k < 5 ; k++)
    cout << notches[k] << endl;
  */
}


void Rotor::rotate(){
  int k = this->notches[0];
  if (this == nullptr)
    return;
  this->reference_no = (this->reference_no + 1) % 26;

  for (int i = 1 ; k > 0 ; i++){
    if (this->reference_no == k)
      (this->left)->rotate();
    k = this->notches[i];
  }
  return;
}

int Rotor::encrypt_forward(int digit){
  if (this == nullptr)
    return digit;
  digit = (digit + this->reference_no) % 26;
  digit = this->rot_configuration[digit];
  /*digit = (this->rot_configuration[(digit + this->reference_no) % 26] - this->reference_no + 26) % 26;
  digit = (digit + 26 - this->reference_no) % 26;
  cout << digit << endl; */
  if (this->left != nullptr)
    digit = (this->left)->encrypt_forward(digit);
  return digit;
}


int Rotor::encrypt_backwards(int digit){
  if (this == nullptr)
    return digit;

  for (int i = 0; i < 26 ; i++)
    if (this->rot_configuration[i] == digit){
      digit = (i - this->reference_no + 26) % 26;
      if (this->right != nullptr)
	digit = (this->right)->encrypt_backwards(digit);
      break;
    }
  return digit;
  
  /*digit = (digit + this->reference_no) % 26;
  //digit = this->rot_configuration[digit];
  //digit = (this->rot_configuration[(digit + this->reference_no) % 26] - this->reference_no + 26) % 26;
  // cout << digit << endl;
  //digit = (digit + 26 - this->reference_no) % 26;
  //digit = (this->right)->encrypt_backwards(digit);
  //return digit; */
}
  
