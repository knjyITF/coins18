#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  //ここから
  int N, i, j, k;
  
  std::cin >> N; //input N
  for (int n = 1; n <= N; n++)
  {
    std::cin >> i >> j >> k; //input i, j, k
    int out = 0;
    //compare inputs
    //iが最大の場合
    if (i > j && i > k)
    {
      out = j > k ? j : k; //j > kならjを出力、でなｋれえばkを出力
    }
    //iが最小の場合
    else if(i < j && i < k)
    {
      out = j < k ? j : k; //j < kならjを、でなければkを
    }
    else out = i; //iが真ん中の場合

    std::cout << "Case " << n << ": " << out << "\n";
  }
}