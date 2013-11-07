#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int main(){
  string input = "John,Doe,1984,4,1,male";
  vector<string> tokens;
  size_t current = 0, found;
  string deleim = ",";

  while((found = input.find_first_of(deleim, current)) != string::npos){
    //cout << found << " - " << input.substr(current,found-current) << endl;
    tokens.push_back(input.substr(current,found-current));
    current = found + 1;
  }
  /*
  for(vector<string>::iterator it=tokens.begin(); it!=tokens.end();it++)
    cout << *it << endl;
    */
  string firstName, lastName;
  firstName = tokens[0];
  lastName = tokens[1];
  //cout << atoi(tokens[2].c_str()) << tokens[3] << tokens[4] << endl;

  int birthdate[3] = {atoi(tokens[2].c_str()),
                      atoi(tokens[3].c_str()),
                      atoi(tokens[4].c_str())};

  /*
  for(int i=0; i<sizeof(birthdate)/sizeof(int);i++){
    cout << birthdate[i] << endl;
  }
  */
  bool isMale = (tokens[5]=="male");
  cout << "Hi " << firstName << " " << lastName << endl;

  return 0;
}

// Hi John Doe
