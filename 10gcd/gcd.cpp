/*
  アルゴリズム
  正整数ａ、ｂ（ａ＞ｂ）の最大公約数を求める手順を示します。
　　ア　ａをｂで割った剰余をｒとする。
　　イ　ｒが０ならばｂが最大公約数である。
　　ウ　ｒが０でないならば、ａ←ｂ、ｒ←ｂとして、アへ戻る。
*/
#include <iostream>
using namespace std;

int gcd(int,int);

int main(){
  cout << gcd(77,28) << endl;
  return 0;
}

int gcd(int a, int b){
  int r;
  r = a % b;
  if(r==0) return b;
  else return gcd(b,r);
}
