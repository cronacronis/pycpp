/*
 * 正整数ａ、ｂ（ａ＞ｂ）の最大公約数を求める手順を示します。
 *　1)　ａをｂで割った剰余をｒとする。
 *　2)　ｒが０ならばｂが最大公約数である。
 *　3)　ｒが０でないならば、ａ←ｂ、ｒ←ｂとして、1)へ。
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
