#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<fstream>
#include<cctype>
#include "enigma.h"
#include "helper.h"
#include "errors.h"

using namespace std;

Enigma::Enigma(int argc, char ** argv){
  plugboard = nullptr;
  reflector = nullptr;
  leftmost_rotor = nullptr;
  rightmost_rotor = nullptr;

  string call_string;
  Rotor* temp;

  if (argc < 4){
    exit_code = INSUFFICIENT_NUMBER_OF_PARAMETERS;
    error_handling("usage: ", exit_code);
  }

  // For-loop parsing the input files, testing their inputs and calling the appropriate constructor
  for (int i = 1 ; i < argc && !exit_code; i++){
    call_string = argv[i];

    //Plugboard
    auto found = call_string.find(".pb");
    if (found != string::npos){
      plugboard = new Plugboard(call_string);
      exit_code = plugboard->exit_code;
    }

    //Reflector
    found = call_string.find(".rf");
    if (found != string::npos){
      reflector = new Reflector(call_string);
      exit_code = reflector->exit_code;
    }

    //Rotor Linked List
    found = call_string.find(".rot");
    if (found != string::npos){

      //This code appends an existing Linked List of Rotors
      if (rotor_count){
	rightmost_rotor = new Rotor(call_string);
	exit_code = rightmost_rotor->exit_code;
	temp->right = rightmost_rotor;
	rightmost_rotor->left = temp;
	temp = rightmost_rotor;
	rotor_count++;
    }
      //This code creates a new Rotor Linked List
      if (!rotor_count){
	leftmost_rotor = new Rotor(call_string);
	exit_code = leftmost_rotor->exit_code;
	rightmost_rotor = leftmost_rotor;
	temp = leftmost_rotor;
	rotor_count++;
      }
    }

    //Rotor Positions
    found = call_string.find(".pos");
    if (found != string::npos){
      exit_code = set_rotors(call_string, rotor_count);
    }
    
    if (exit_code){
      error_handling(call_string, exit_code);
      break;
    }
  }
}
/*END OF FUNCTION*/

int Enigma::set_rotors(string const& call_string, int rotor_count){
  int count = 0, exit = 0;
  string pos_digit_string;
  ifstream is_position;
  int pos_configuration[rotor_count];
  
  //Opening the file
  is_position.open(call_string, ios::in);
  if (!is_position){
    exit = ERROR_OPENING_CONFIGURATION_FILE;
  }
  //Inserting and the next digit from the file
  is_position >> pos_digit_string;
  while (!exit  && !is_position.eof()){
    
    is_numeric(pos_digit_string, exit);
    if (!exit)
      input_in_range(pos_digit_string, exit);
    if (!exit)
      pos_configuration[count] = stoi(pos_digit_string);
    if (!exit)
      is_position >> pos_digit_string;
    count++;
  }

  if (!exit && count < rotor_count)
	exit = NO_ROTOR_STARTING_POSITION;

  //Setting the offset reference number to the starting position for all rotors in the list
  if (!exit){
    Rotor* here = leftmost_rotor;
    
    for (int rotor = 0 ; here ; rotor++){
      here->reference_no = pos_configuration[rotor]; 
      here = here->right;
      }

    /*
    for (int rotor = 0 ; here ; rotor++){
      for (int i = 0 ; i <= 25 ; i++){
	if (here->rot_configuration[i] == pos_configuration[rotor]){
	  here->reference_no = i;
	  break;
	}
      }
      here = here->right;
    }*/
  }
  return exit;
}

/*END OF FUNCTION*/

int Enigma::encryption(int digit){

  if (rightmost_rotor)
    rightmost_rotor->rotate();

  digit = plugboard->encrypt(digit);

  if (rightmost_rotor)
    digit = rightmost_rotor->encrypt_forward(digit);

  digit = reflector->encrypt(digit);

  if (leftmost_rotor)
    digit = leftmost_rotor->encrypt_backwards(digit);

  digit = plugboard->encrypt(digit);

  return static_cast<char>(digit) + 65;
}
/*END OF FUNCTION*/

void Enigma::clear_rotor(){
  Rotor* current = leftmost_rotor;
  Rotor* next;
  while (current){
    next = current->right;
    delete current;
    current = next;
  }
}
/*END OF FUNCTION*/

Enigma::~Enigma(){
  delete plugboard;
  delete reflector;
  clear_rotor();
}
/*END OF FUNCTION*/
  
