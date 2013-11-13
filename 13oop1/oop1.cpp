#include <iostream>
#include <string>
using namespace std;

class Staff601{
public:
  Staff601();
  string course;
  string role;
  string name;
  int building;
  int room;
  int age;
  string salutation();
};

Staff601::Staff601()
  :course("6.01"),role(""),building(34),room(501),name(""),age(0){
    cout << "Called Staff601" << endl;
}

string Staff601::salutation(){
  return role + " " + name;
}


int main(){
  Staff601 pat = Staff601();
  cout << pat.course << endl;

  pat.name = "Pat";
  pat.age = 10;
  pat.role = "Professor";

  cout << pat.building << endl;
  pat.building = 32;
  cout << pat.building << endl;

  cout << pat.salutation() << endl;

  return 0;
}
