
#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<fstream>
#include<cctype>
#include "enigma.h"

// DELETE ALL THE HELPER FOR LOOOPS
// APPROPRIATELY COMMENT THE FILESy


using namespace std;


int main(int argc, char** argv){
  char letter, encrypted_letter;
  Enigma enigma(argc, argv);

  if (enigma.exit_code == 0)
    cout << "Enigma was successfully inititalised!" << endl;
  else {
    error_handling("", enigma.exit_code);
    return enigma.exit_code;
  }


  cout <<  "Please enter a message to be encrypted (UPPERCASE ALPHABETICAL CHARACTERS ONLY)" << endl;
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


  

 
