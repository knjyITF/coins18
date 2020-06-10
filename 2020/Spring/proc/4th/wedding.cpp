#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

int find_next(int *next, int minnext)
{
  for (int i = 0; i != sizeof(next); i++)
  {
    if (next[i] == minnext)
      return i;
  }
  return -1;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  //ここから
  int cases;
  std::cin >> cases;

  for (int i = 0; i < cases; i++)
  {
    int M, C;
    std::cin >> M >> C;
    int garment[20][20];
    for (int i = 0; i < 20; i++)
    {
      for (int j = 0; j < 20; j++)
      {
        garment[i][j] = 0;
      }
    }

    for (int c = 0; c < C; c++)
    {
      int K;
      std::cin >> K;
      int gar[K];
      for (int k = 0; k < K; k++)
      {
        std::cin >> gar[k];
      }
      std::sort(gar, gar + K, std::greater<>());
      for (int k = 0; k < K; k++)
      {
        garment[c][k] = gar[k];
      }
    }
    //ここまででgarment[c][k]に降順で値段が入っている
    bool found = false;

    int cost = 0;
    int next[C];
    int k_of_c[C];
    int minnext = 334;
    int nextc = 0;

    for (int c = 0; c < C; c++)
    {
      cost += garment[c][0];
      next[c] = garment[c][0] - garment[c][1];
      k_of_c[c] = 0;
      if (next[c] < minnext)
        minnext = next[c];
    }
    while (!found)
    {
      if (cost <= M)
        found = true;
      else
      {
        nextc = find_next(next, minnext);
        k_of_c[nextc]++;
        cost = cost - garment[nextc][k_of_c[nextc] - 1] + garment[nextc][k_of_c[nextc]];
        next[nextc] = garment[nextc][k_of_c[nextc]] - garment[nextc][k_of_c[nextc] + 1];
        if (next[nextc] < minnext)
          minnext = next[nextc];
      }
    }
    std::cout << cost << "\n";
  }
}