#include <iostream>
using namespace std;

long double pow(int a, int n){
  long double res = 1;
  for(int i=0;i<n;i++){
    res *= a;
  }
  return res;
}

int main(int argc, char const *argv[])
{
  /* code */
  // cout << pow(2,100) << endl;
  //cout << pow(2,1024) << endl;
  cout << pow(2,1000007) << endl;
  return 0;
}
