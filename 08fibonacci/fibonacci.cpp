#include <iostream>
#include <vector>
using namespace std;

static vector<int> memoTable;

int memorizedFib(int n){
  if(n <= 2){
    return 1;
  }

  if(find(memoTable.begin(), memoTable.end(), n) != memoTable.end()) {
    return memoTable[n];
  }
  memoTable[n] = memorizedFib(n-1) + memorizedFib(n-2);
  return memoTable[n];
}

int fibonacci(int n){
  // 0 and 1
  if( n==0 || n == 1){
    return 1;
  }else{
    return fibonacci(n-1) + fibonacci(n-2);
  }
}

int main(){
  cout << fibonacci(10) << endl;
  return 0;
}

