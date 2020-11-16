#include "reflector.h"

using namespace std;

  
Reflector::Reflector(string const& call_string){
  exit_code = 0;
  int count = 0;
  string rf_digit_string;
  ifstream is_reflector;
  
  //Opening the file
  is_reflector.open(call_string, ios::in);
  if (!is_reflector){
    exit_code = 11;
  }
  //Inserting the next digit from the file
  is_reflector >> rf_digit_string;
  while (exit_code == 0 && !is_reflector.eof()){

    if (exit_code == 0)
      check_input_numerical(rf_digit_string, exit_code);
    if (exit_code == 0)
      check_input_in_range(rf_digit_string, exit_code);
    if (exit_code == 0)
      rf_configuration[count] = stoi(rf_digit_string);
    if (exit_code == 0){
      if (!is_input_repetitive(count, rf_configuration))
	  exit_code = 9;
    }
    if (exit_code == 0)
      is_reflector >> rf_digit_string;
    count++;
  }
  if (exit_code == 0 && count != 26)
    exit_code = 10;
  is_reflector.close();
  /*
  cout << "Reflector" << endl;
  for (int j = 0 ; j < 26 ; j++)
    cout << rf_configuration[j] << endl;
  */
}

int Reflector::encrypt(int digit){
  int remainder;
  for (int i = 0 ; i < 26 ; i++){
    if (this->rf_configuration[i] == digit){
      remainder = i % 2;
      if (remainder == 0)
	return (this->rf_configuration[i+1]);
      if (remainder == 1)
	return (this->rf_configuration[i-1]);
    }
  }
  return digit; //This return statement will never be reached, since the clauses above are MECE and no faulty rf configuration will be encrypted. Only included to suppress warning. 
}
