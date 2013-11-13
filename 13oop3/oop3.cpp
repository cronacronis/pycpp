#include <iostream>
#include <string>

using namespace std;

class A{
public:
  int x = 1;
  string y = "hello";
};

class B{
public:
  string z = "bye";
};

class C :public A, public B
{
public:
  string salutation(){
    // c++11
    return to_string(x) + " " + y + " " + z;
  }
};

int main(int argc, char const *argv[])
{
  C inst = C();
  cout << inst.salutation() << endl;
  inst.x = 100;
  cout << inst.salutation() << endl;
  return 0;
}
