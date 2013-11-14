#include <iostream>
#include <string>
using namespace std;

class Staff601{
public:
  string course;
  string name;
  string role;
  int age;
  int building;
  int room;
  int salary;

public:
  void giveRaise(float percentage){
    salary = salary + salary * percentage;
  }
};

class Prof601 :public Staff601{
public:

  Prof601(string name,int age)
  {
    this->salary = 10000000;
    this->name = name;
    this->role = "Professor";
    giveRaise((age - 18) * 0.03);
  }

  string salutation(){
    return role + " " + name;
  }

};

int main(){
  Prof601 pat = Prof601("Pat", 60);
  //cout << pat.salutation() << endl;
  return 0;
}
