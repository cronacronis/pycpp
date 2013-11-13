#include <iostream>
using namespace std;

int main(){
  char prefix[] = "Hello ";
  char n1[30];
  char n2[30];

  cout << "Enter your name" << endl;
  cin >> n1;

  cout << "Enter another name" << endl;
  cin >> n2;

  cout << prefix << n1 << " and " << n2 << endl;
  return 0;
}
