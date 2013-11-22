#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Calendar{
  int current_dt;
  int current_mon;
  int current_year;
  int space_count;
public:
  Calendar();
  ~Calendar();
  bool is_leapyear(int);
  int daycount_in_month(int);
  int get_weekday(int,int,int);
  int get_space_cnt();
  string show_date_string(int);
  void show(int,int,int);
};

Calendar::Calendar(){}

Calendar::~Calendar(){}

// 西暦で示した年が4で割り切れる年は閏年
// 西暦で示した年が100で割り切れる年は閏年ではない
// 西暦で示した年が400で割り切れる年は閏年
bool Calendar::is_leapyear(int y){
  if((y % 4 == 0 && y%100 !=0) || y % 400 == 0)
    return true;
  return false;
}

// ツェラーの公式
// 月を3月の前で切って、3月から始めて2月で終わるという考え方
// 0:土,1:日,2:月,3:火,4:水,5:木,6:金
int Calendar::get_weekday(int y,int m,int d){
  int j, k,h;
  y =  (m==1 || m==2)? y-1:y;
  j = y / 100;
  k = y % 100;
  m = (m==1 || m==2)? m+12:m;

  h = d + (26 * (m + 1) / 10) + k + (k/4) + (j/4) - (2*j);
  h %= 7;

  // 日曜日から始まるカレンダー上の１日目のポジションを調整
  // 0以下の場合が微妙なんだけど・・・
  return (h<0)? 7+h:h;
}

string Calendar::show_date_string(int x){
  string s;
  switch(x){
    case 0: s = "土"; space_count=6; break;
    case 1: s = "日"; space_count=0; break;
    case 2: s = "月"; space_count=1; break;
    case 3: s = "火"; space_count=2; break;
    case 4: s = "水"; space_count=3; break;
    case 5: s = "木"; space_count=4; break;
    case 6: s = "金"; space_count=5; break;
    default: s = "わからん"; break;
  }
  return s;
}

int Calendar::daycount_in_month(int m){
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

int Calendar::get_space_cnt(){ return space_count; }

void Calendar::show(int y, int m, int d){

  int i,sp_cnt;
  string w = " Su Mo Tu We Th Fr Sa";
  int dt_pos = get_weekday(y,m,d);
  cout << dt_pos << " => Start日は "<< show_date_string(dt_pos) << "曜日です" << endl;
  sp_cnt = get_space_cnt();

  //cout << "空白の数：" << sp_cnt << endl;
  // output calendar
  cout << endl << "        "
      << m << "-" << y << endl;
  cout << w << endl;

  int len = daycount_in_month(m);

  cout << " ";
  // カレンダー表示は日曜日からなので空白を挿入
  for(i=0; i<sp_cnt;i++){
    cout << setw(3) << right << " ";
  }

  for(i=1; i<=len; i++){
    cout << setw(2) << right << i << " ";
    // 改行する位置
    if((i+sp_cnt)%7==0) cout << endl << " ";
  }
  cout << endl;
}

// 実行する
int main(int argc, char const *argv[])
{
  int y,m;

  cout << "input year" << endl;
  cin >> y;
  cout << "input month" << endl;
  cin >> m;

  Calendar *cal;
  cal->show(y,m,1);

  return 0;
}

