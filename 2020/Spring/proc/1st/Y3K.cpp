#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  //ここから
  int p, d, m, y; //増やす日数、現在の日、月、年
  for (;;)
  {
    std::cin >> p >> d >> m >> y; //input p, d, m, y
    if (p == 0 && d == 0 && m == 0 && y == 0)
      break; //終了条件

    //計算前の日付の設定
    std::tm t = {};
    t.tm_year = -1900 + y;
    t.tm_mon = -1 + m;
    t.tm_mday = d;

    //日付の計算
    t.tm_mday += p;
    if (std::mktime(&t) != (time_t)-1)
    {
      std::asctime(&t);
    }

    //書き出し
    std::cout << t.tm_mday << " " << t.tm_mon + 1 << " " << t.tm_year + 1900 << "\n";
  }
}