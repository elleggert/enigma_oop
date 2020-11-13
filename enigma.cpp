#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<fstream>
#include<cctype>
#include "enigma.h"
#include "helper.h"

using namespace std;


Enigma::Enigma(int argc, char ** argv){
  exit_code = 0;
  plugboard = nullptr;
  reflector = nullptr;
  leftmost_rotor = nullptr;
  rightmost_rotor = nullptr;
  rotor_count = 0;

  int found;
  string call_string;
  Rotor* temp;

  cout << "You have entered " << argc << " arguments." << endl;

  cout << "The arguments are: " << endl;

  for (int i = 0; i < argc; ++i) 
        cout << argv[i] << endl;

  if (argc < 4)
    exit_code = 1;

  for (int i = 1 ; i < argc && exit_code == 0; i++){
    call_string = argv[i];
    found = call_string.find(".pb");
    if (found != string::npos){
      plugboard = new Plugboard(call_string);
      exit_code = plugboard->exit_code;
    }

    found = call_string.find(".rf");
    if (found != string::npos){
      reflector = new Reflector(call_string);
      exit_code = reflector->exit_code;
    }
    
    found = call_string.find(".rot");
    if (found != string::npos){
      if (rotor_count > 0){
	rightmost_rotor = new Rotor(call_string);
	exit_code = rightmost_rotor->exit_code;
	temp->right = rightmost_rotor;
	rightmost_rotor->left = temp;
	temp = rightmost_rotor;
	rotor_count++;
    }
      if (rotor_count == 0){
	leftmost_rotor = new Rotor(call_string);
	exit_code = leftmost_rotor->exit_code;
	rightmost_rotor = leftmost_rotor;
	temp = leftmost_rotor;
	rotor_count++;
      }
    }

    found = call_string.find(".pos");
    if (found != string::npos){
      exit_code = set_rotor_starting_position(call_string, rotor_count);
    }
    
    if (exit_code == 0){
      cout << " Configuration file " << call_string << " was successfully loaded. " << endl;
    }
    else
      error_handling(call_string, exit_code);
  }
  if (exit_code == 0)
    cout << "Enigma was successfully inititalised!" << endl;
}

int Enigma::set_rotor_starting_position(string const& call_string, int rotor_count){
  int count = 0, exit = 0;
  string pos_digit_string;
  ifstream is_position;
  int pos_configuration[rotor_count];
  
  //Opening the file
  is_position.open(call_string, ios::in);
  if (!is_position){
    exit = 11;
  }
  //Inserting the next digit from the file
  is_position >> pos_digit_string;
  while (exit == 0 && !is_position.eof()){
    
    check_input_numerical(pos_digit_string, exit);
    if (exit == 0)
      check_input_in_range(pos_digit_string, exit);
    if (exit == 0)
      pos_configuration[count] = stoi(pos_digit_string);
    if (exit == 0)
      is_position >> pos_digit_string;
    count++;
  }

  if (exit == 0 && count < rotor_count){
	exit = 8;
    }
  cout << "Rotor Position" << endl;
  for (int j = 0 ; j <= rotor_count ; j++)
    cout << pos_configuration[j] << endl;

  if (exit == 0){
    Rotor* here = leftmost_rotor;
    for (int rotor = 0 ; here != nullptr ; rotor++){
      here->reference_no = pos_configuration[rotor];
      here = here->right;
    }
  }
  return exit;
}

int Enigma::encryption(int digit){

  rightmost_rotor->rotate();

  digit = plugboard->encrypt(digit);
  digit = rightmost_rotor->encrypt_forward(digit);
  digit = reflector->encrypt(digit);
  digit = leftmost_rotor->encrypt_backwards(digit);
  digit = plugboard->encrypt(digit);

  return static_cast<char>(digit) + 65;
}


void Enigma::clear_rotor(){
  Rotor* current = leftmost_rotor;
  Rotor* next;
  while (current != nullptr){
    next = current->right;
    delete current;
    current = next;
  }
}

Enigma::~Enigma(){
  delete plugboard;
  delete reflector;
  clear_rotor();
}

  
