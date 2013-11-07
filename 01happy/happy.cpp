#include <iostream>
#include <string>
using namespace std;

void happy(){
  cout << "Happy Birthday to you!" << endl;
}

void sing(string P){
  happy();
  happy();
  cout << "Happy Birthday dear " << P << "!" << endl;
  happy();
}

int main(){
  sing("Fred");
  return 0;
}
