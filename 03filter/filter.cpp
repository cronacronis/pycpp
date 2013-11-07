#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Person
{
  string name;
  int age;
};

int main(){
  Person mary,joe,ruth,bob,jenny;
  mary.name = "Mary";
  mary.age = 27;
  joe.name = "Joe";
  joe.age = 30;
  ruth.name = "Ruth";
  ruth.age = 43;
  bob.name = "Bob";
  bob.age = 17;
  jenny.name = "Jenny";
  jenny.age = 22;

  Person input[] = {mary,joe,ruth,bob,jenny};
  size_t len = sizeof(input)/sizeof(Person);

  vector<Person> v;

  for(int i=0;i<len;i++){
    if(input[i].age < 30){
      v.push_back(input[i]);
    }else{
      cout << "HAHA " << input[i].name << " is too old" << endl;
    }
  }

  cout << "There are " << v.size() << " young people" << endl;

  return 0;
}
/*
HAHA Joe is too old!
HAHA Ruth is too old!
There are 3 young people
*/
