#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  //ここから
  int i, j;

  for (;;)
  {
    std::cin >> i >> j; //input i, j
    if (cin.fail()) break;
    int N, count;
    int count_max = 0;

    std::cout << i << " " << j << " ";
    //i < j にする
    if (i > j)
      swap(i, j);

    //3n_1判定
    for (int n = i; n <= j; n++)
    {
      N = n;
      count = 0;
      while (N != 1)
      {
        if (N % 2 == 1)
          N = 3 * N + 1;
        else
          N = N / 2;
        ++count;
      }
      ++count;
      if (count > count_max)
        count_max = count;
    }
    std::cout << count_max << "\n";
  }
}