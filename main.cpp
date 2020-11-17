#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<fstream>
#include<cctype>
#include "enigma.h"
#include "errors.h"

using namespace std;

int main(int argc, char** argv){
  char letter, encrypted_letter;
  Enigma enigma(argc, argv);

  if (enigma.exit_code)
    return enigma.exit_code;
  
  cout <<  "Please enter a message to be encrypted" << endl;

  
  while (cin >> ws >> letter){
    
    int digit = static_cast<int>(letter) - 65;

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


  

 
