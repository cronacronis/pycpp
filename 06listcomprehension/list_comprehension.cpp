#include <iostream>
#include <string>
using namespace std;

int main(){
  string ppl[] = {"Alice", "Bob", "Carol", "Doug"};
  auto excited_ppl = [&] () {
    // ラムダ式中でのローカル変数へのアクセスは，
    // [] の部分を [&] にすることで可能になる．
    for(int i=0; i < sizeof(ppl)/sizeof(string); i++)
      cout << *(ppl + i) << "!!, ";
    cout << endl;
  };

  auto ppl_len = [&] () {
    for(int i=0; i < sizeof(ppl)/sizeof(string); i++)
      cout << (*(ppl + i)).size() << ", ";
    cout << endl;
  };

  excited_ppl();
  ppl_len();

  return 0;
}
