#include <bits/stdc++.h>
using namespace std;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  //ここから
  for (;;)
  {
    int d, k;
    std::cin >> d >> k;
    if (d == 0 && k == 0)
      break;
    int dragon[d];
    int knight[k];
    for (int n = 0; n < d; ++n)
    {
      std::cin >> dragon[n];
    }
    for (int n = 0; n < k; ++n)
    {
      std::cin >> knight[n];
    }
    //ここまででinput処理完了

    std::sort(dragon, dragon + d);
    std::sort(knight, knight + k);
    //inputをソート(扱いやすくするため)

    int last = 0;
    bool lose = false;
    int cost = 0;

    if (d > k) lose = true;
    
    for(int i = 0; i < d; i++)
    {
      for (int j = last; j < k; j++)
      {
        if(dragon[i] <= knight[j])
        {
          cost += knight[j];
          last = j+1;
          break;
        }
        if(dragon[i] > knight[j] && dragon[i] > knight[k])
        {
          lose = true;
          break;
        }
      }
    }

    if (lose == false)
    {
      std::cout << cost << "\n";
    }
    else if (lose == true)
    {
      std::cout << "Loowater is doomed!\n";
    }
  }
}