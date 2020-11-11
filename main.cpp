
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
  Enigma enigma(argc, argv);


  cout << "Exit with following error code: " << enigma.exit_code << endl;

  return 0;
}
  

 
