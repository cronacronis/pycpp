#include <iostream>
#include <map>
using namespace std;

void swap(int *a,int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}


void insertion_sort(int *array, unsigned int size){
  int i,j;
  for (i = 1; i <size ; i++) {
    for (j = i; j > 0 && array[j-1] > array[j] ; j--){
      swap(array[j-1] , array[j]); //要素の交換
    }
  }
}

// 配列に負でない整数が格納されている。
// これらの整数の中から大きい順に3つの数字とその添字を出力せよ
int main(int argc, char const *argv[])
{

  int a[] = {12, 6, 8, 3, 10, 1, 0, 9};
  size_t len = sizeof(a)/sizeof(int);

  // キーがint、値がintのmap
  map<int,int> t;
  int i;

  for(i=0; i<len; i++)
    t[i] = a[i];

  insertion_sort(a,len);

  for(i=0; i< 3;i++){

    for(map<int,int>::iterator it=t.begin();it!=t.end();it++){
      if(it->second == a[len-1-i]){
        cout << it->first << " -> " << it->second << endl;
        break;
      }
    }
  }

  return 0;
}
