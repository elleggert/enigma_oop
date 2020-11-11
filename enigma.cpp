

#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<fstream>
#include<cctype>
#include "enigma.h"

using namespace std;


Enigma::Enigma(int argc, char ** argv){
  exit_code = 0;
  plugboard = nullptr;
  reflector = nullptr;
  rotor_count = 0;

  int found;
  string call_string;

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
    /*
    found = call_string.find(".rot");
    if (found != string::npos){
      rotor_count++;
      rotor = new rotor(call_string);
      exit_code = rotor->exit_code;
      }*/
  }
  if (exit_code == 0)
    cout << "Enigma was successfully inititalised!" << endl;
}
