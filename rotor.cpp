#include "rotor.h"
#include "errors.h"

using namespace std;


Rotor::Rotor(string const& call_string){
  int count = 0;
  string rot_digit_string;
  ifstream is_rotor;

  is_rotor.open(call_string, ios::in);
  if (!is_rotor)
    exit_code = ERROR_OPENING_CONFIGURATION_FILE;

  //FILLING THE ROTOR
  is_rotor >> rot_digit_string;
  while (!exit_code  && count <= 25){

    
    if (!exit_code)
      is_numeric(rot_digit_string, exit_code);
    if (!exit_code)
      input_in_range(rot_digit_string, exit_code);
    if (!exit_code)
      rot_configuration[count] = stoi(rot_digit_string);
    if (!exit_code && !is_repetitive(count, rot_configuration))
      exit_code = INVALID_ROTOR_MAPPING;
    if (!exit_code)
      is_rotor >> rot_digit_string;
    count++;
  }

  // FILLING THE NOTCHES
  if (!exit_code && is_rotor){
    for (int j = 0; !is_rotor.eof(); j++){
      if (!exit_code)
	is_numeric(rot_digit_string, exit_code);
      if (!exit_code)
	input_in_range(rot_digit_string, exit_code);
      if (!exit_code){
	notches[j] = stoi(rot_digit_string);
	notches[j+1] = -1;
	is_rotor >> rot_digit_string;
      }
    }
  }
  is_rotor.close();
}
/*END OF FUNCTION*/

void Rotor::rotate(){
  int k = this->notches[0];
 
  this->reference_no = (this->reference_no + 1) % 26;

  for (int i = 1 ; k > 0 ; i++){
    if (this->reference_no == k){
      if (this->left) 
	(this->left)->rotate();
    }
    k = this->notches[i];
  }
  return;
}
/*END OF FUNCTION*/

int Rotor::encrypt_forward(int digit){
  digit = (digit + this->reference_no) % 26;
  digit = this->rot_configuration[digit];
  if (this->left)
    digit = (this->left)->encrypt_forward(digit);
  return digit;
}
/*END OF FUNCTION*/

int Rotor::encrypt_backwards(int digit){
  for (int i = 0; i < 26 ; i++)
    if (this->rot_configuration[i] == digit){
      digit = (i - this->reference_no + 26) % 26;
      if (this->right)
	digit = (this->right)->encrypt_backwards(digit);
      break;
    }
  return digit;
}
/*END OF FUNCTION*/
