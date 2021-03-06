#include "enigma.h"

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


  

 
