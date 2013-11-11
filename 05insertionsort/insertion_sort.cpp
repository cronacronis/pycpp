#include <iostream>

using namespace std;

int* insertionSort(int *x,size_t len);

void disp_result(const int x[],int len){
  for(int i=0;i<len;i++)
    cout << x[i] << ", ";
  cout << endl;
}

int main(){
  int input[] = {8, 3, 9, 15, 29, 7, 10};
  //int input[] = {5, 3, 4, 1, 2};
  int len = sizeof(input)/sizeof(int);
  disp_result(input,len);

  insertionSort(input,len);
  disp_result(input,len);
  return 0;
}

int* insertionSort(int *x,size_t len){
  int i, j,key;
  for(i=0;i<len;i++){
    // key：現在の値
    key = x[i];
    // j：一つ前のインデックス
    j = i -1;
    while(j >=0 && (x[j] > key)){
      x[j+1] = x[j];
      j--;
    }
    x[j+1] = key;
  }
  return x;
}
