/*
* ３の倍数と３のつく数字のときだけアホになります
* ルールは以下の通り
* (1) 1から順番に数を表示する
* (2) その数が3の倍数、もしくは3のつく数字であれば"Aho"と表示する
* 要するに"1 2 Aho 4 5 Aho 7 8 Aho 10 11 Aho Aho 14 ･･･"と出力される
*/

#include <iostream>
#include <string>
using namespace std;

void nabeatsu(int);

int main(int argc, char const *argv[])
{
  nabeatsu(50);
  return 0;
}

void nabeatsu(int n){
  size_t found;
  string str;
  for(int i=0;i<n;i++){
    str = to_string(i);
    found=str.find("3");
    if(i%3==0 ||(found!=string::npos)){
      cout << "Aho, ";
    }else{
      cout << i << ", ";
    }
  }
  cout << endl;
}
