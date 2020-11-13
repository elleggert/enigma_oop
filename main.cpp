
#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<fstream>
#include<cctype>
#include "enigma.h"

// TODO: MAKE SURE THAT THIS ALSO WORKS WITH AN EMPTY PLUGBOARD
// TODO: DEAL WITH CASE WHERE NO ROTOR SPECIFICATIONS ARE GIVEN OR WHERE ONLY POSITIONS ARE GIVEN
// ADD THE ROTOR POSITIONS FILE. Make sure the function counts number of rotor arguments before. Then check the input. 
using namespace std;


int main(int argc, char** argv){
  char letter, encrypted_letter;
  Enigma enigma(argc, argv);


  cout <<  "Please enter a message to be encrypted (UPPERCASE ALPHABETICAL CHARACTERS ONLY, any number to quit)" << endl;
  while (cin >> ws >> letter){
    int digit = static_cast<int>(letter) - 65;
    if (digit < 0 || digit > 25){
      enigma.exit_code = 2;
      error_handling("Failure", enigma.exit_code);
      return enigma.exit_code;
    }

    encrypted_letter = enigma.encryption(digit);
    cout << encrypted_letter;
  }
  cout << endl;
  return enigma.exit_code;
}


  

 
