#include <iostream>
using namespace std;

double pow(int a, int n){
  double res = 1;
  while(n > 0){
    if(n & 1){
      // 1bit目がたっていればaをかける
      res *= a;
    }
    //
    a = a*a;
    // bitをずらす
    // 1010->101->10->1
    n >>= 1;
  }
  return res;
}

int main(int argc, char const *argv[])
{
  cout << pow(2,0) << endl;
  cout << pow(2, 1) << endl;
  cout << pow(2, 2) << endl;
  cout << pow(2,10) << endl;
  cout << pow(3,3) << endl;
  //cout << pow(2, 1024) << endl;
  //cout << pow(2, 10000007) << endl;

  return 0;
}
