#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
  string aster[] = {"山羊座", "水瓶座", "魚座", "牡羊座",
                    "牡牛座", "双子座", "蟹座", "獅子座",
                    "乙女座", "天秤座", "蠍座", "射手座"};
  int day_list[] = {20, 19, 20, 20, 20, 21, 23, 23, 23, 23, 22, 22};

  int m,d;
  cout << "月を入力：" << endl;
  cin >> m;

  cout << "日を入力：" << endl;
  cin >> d;

  auto f = [&]{
    int num, index;
    num = (d > day_list[m-1])? 1:0;
    index = m-13+num;
    if(index < 0) index += 12;
    return aster[index];
  };

  cout << f() << endl;

  return 0;
}
