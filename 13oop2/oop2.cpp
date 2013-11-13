#include <iostream>
#include <string>
using namespace std;

class Staff601{
  // private
  string name, role;
  int age, salary;
public:
  string course;
  int building, room;
  Staff601(string,string,int,int);
  string salutation();
};

int main(int argc, char const *argv[])
{
  Staff601 pat = Staff601("Pat", "Professor", 60, 100000);
  cout << pat.salutation() << endl;
  return 0;
}

Staff601::Staff601(string a,string b,int c,int d)
  :course("6.01"),building(34),room(501)
{
  name = a;
  role = b;
  age = c;
  salary = d;
}

string Staff601::salutation(){
  return role + " " + name;
}
