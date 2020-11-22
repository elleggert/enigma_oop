#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<fstream>
#include<cctype>
#include "enigma.h"
#include "errors.h"

//DELETE COMMENTS
//WORK IN FEEDBACK FROM ASSIGNMENT 1 --> Remove overlong lines
//TEST THE ENTIRE SET UP WITHOUT ROTORS AND REREAD WHETHER POSITION IS ALWAYS GIVEN 
//REMOVE ALL INCLUDE DIRECTIVES THAT ARE NOT USED
//SHORTEN THE LINE IN ROTOR:CPP HELPER:CPP :H AND ERRORS:H

using namespace std;

int main(int argc, char** argv){
  char letter, encrypted_letter;
  Enigma enigma(argc, argv);

  if (enigma.exit_code)
    return enigma.exit_code;

  while (cin >> ws >> letter){
    
    int digit = static_cast<int>(letter) - ASCII_A;

    int_input_in_range(digit, enigma.exit_code);
    
    if (enigma.exit_code){
      error_handling(string(1,letter), enigma.exit_code);
      return enigma.exit_code;
    }
    encrypted_letter = enigma.encryption(digit);
    cout << encrypted_letter;    
  }
  cout << endl;
  return enigma.exit_code;
}


  

 
