#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
using namespace std;

bool is_leapyear(int);
int daycount_in_month(int);
int get_weekday(int,int,int);

int main(int argc, char const *argv[])
{
  int y,m,i,space_num,first_dt = 1;
  string dt;
  string w = " Su Mo Tu We Th Fr Sa";

  cout << "input year" << endl;
  cin >> y;
  cout << "input month" << endl;
  cin >> m;

  int first_dt_pos = get_weekday(y,m,first_dt);
  first_dt_pos = (first_dt_pos<0)? 7+first_dt_pos:first_dt_pos;

  switch(first_dt_pos){
    case 0:
      dt = "土";
      space_num = 6;
    break;
    case 1:
      dt = "日";
      space_num = 0;
      break;
    case 2:
      dt = "月";
      space_num = 1;
      break;
    case 3:
      dt = "火";
      space_num = 2;
      break;
    case 4:
      dt = "水";
      space_num = 3;
      break;
    case 5:
      dt = "木";
      space_num = 4;
      break;
    case 6:
      dt = "金";
      space_num = 5;
      break;
    default:
      dt = "aaaaaaa";
      break;
  }

  cout << first_dt_pos << " => Start日は "<< dt << "曜日です" << endl;

  cout << "空白の数：" << space_num << endl;

  // output calendar
  cout << endl << "        "
      << m << "-" << y << endl;
  cout << w << endl;
  int len = daycount_in_month(m);
  cout << " ";

  // カレンダー表示は日曜日からなので空白を挿入
  for(i=0; i<space_num;i++){
    cout << setw(3) << right << " ";
  }

  for(i=1; i<=len; i++){
    cout << setw(2) << right << i << " ";
    // 改行する位置
    if((i+space_num)%7==0) cout << endl << " ";
  }

  cout << endl;

  return 0;
}

/*
  ツェラーの公式
  月を3月の前で切って、3月から始めて2月で終わるという考え方
  0:土,1:日,2:月,3:火,4:水,5:木,6:金
*/

int get_weekday(int y,int m,int d){
  int j, k,h;
  y =  (m==1 || m==2)? y-1:y;
  j = y / 100;
  k = y % 100;
  m = (m==1 || m==2)? m+12:m;

  h = d + (26 * (m + 1) / 10) + k + (k/4) + (j/4) - (2*j);
  h %= 7;
  // 0以下の場合が微妙なんだけど・・・
  return (h<0)? 7+h:h;
}

int daycount_in_month(int m){
  int count;
  switch(m){
    case 2:
      if(is_leapyear(m))
        count = 29;
      else
        count = 28;
    break;
    case 4:
    case 6:
    case 9:
    case 11:
      count = 30;
    break;
    default:
      count = 31;
    break;
  }
  return count;
}

bool is_leapyear(int y){
  /*
    西暦で示した年が4で割り切れる年は閏年です
    西暦で示した年が100で割り切れる年は閏年ではありません
    西暦で示した年が400で割り切れる年は閏年です
  */
  if((y % 4 == 0 && y%100 !=0) || y % 400 == 0)
    return true;
  return false;
}

