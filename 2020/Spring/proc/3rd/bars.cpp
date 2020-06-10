#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
  //ここから
  int cases;
  std::cin >> cases;

  for (int c = 0; c < cases; ++c)
  {
    int length, b;
    std::cin >> length >> b; //input length, bars
    int bar[b];
    for (int n = 0; n < b; ++n)
    {
      std::cin >> bar[n];
    }

    //ここから計算
    bool dp[b+1][length+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;

    for (int i = 0; i < b; ++i)
    {
      for (int j = 0; j <= length; ++j)
      {
        dp[i+1][j] |= dp[i][j];
        if(j >= bar[i]) dp[i+1][j] |= dp[i][j-bar[i]];
      }
    }
    if (dp[b][length]) std::cout << "YES\n";
    else std::cout << "NO\n";
  }
}