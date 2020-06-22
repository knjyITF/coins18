#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  //ここから
  int cases;
  std::cin >> cases;
  
  for (int n = 0; n < cases; ++n)
  {
    int characters;
    std::cin >> characters;
    char chara[characters];
    int cost[characters];
    for(int c = 0; c < characters; ++c)
    {
      std::cin >> chara[c] >> cost[c];
    }
    int lines;
    std::cin >> lines;
    string news;
    std::cin >> news;
    for(int l = 0; l < lines; l++)
    {
      string t;
      getline(cin, t);
      news += t;
    }
    //ここまででnewsにnewsの内容が全部入ってるはず
    //ここから検索フェーズ
    int countchr[characters];
    for(int c = 0; c < characters; c++)
    {
      int count = 0;
      int i = 0;
      while(news[i] != '\0')
      {
        if(news[i] == chara[c]) ++count;
        ++i;
      }
      countchr[c] = count;
    }

    //価格計算
    int sum = 0;
    for(int c = 0; c < characters; c++)
    {
      sum += countchr[c]*cost[c];
    }
    double out = (double)sum / 100;
    std::cout << fixed << setprecision(2) << out << "$\n";
  }
}