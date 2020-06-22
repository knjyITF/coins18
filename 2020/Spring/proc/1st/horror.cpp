#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  //ここから
  int T, N, a, max;
  
  std::cin >> T; //input T
  for (int t = 1; t <= T; t++)
  {
    std::cin >> N; //input N
    max = 0;
    for (int n = 1; n <= N; n++){
      std::cin >> a;
      max = a > max ? a : max;
    }
    std::cout << "Case " << t << ": " << max << "\n";
  }
}