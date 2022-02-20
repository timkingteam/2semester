#include <iostream>
#include <vector>

int main() {
  int power;
  std::cin >> power;

  std::vector<std::vector<int>> peaceAmount(power+1, std::vector<int>(power+1));
  peaceAmount[0][0] = 1;
  for (int curPower = 0; curPower <= power; ++curPower) {
    for (int maxVal = 0; maxVal <= power; ++maxVal) {
      for (int wherePush = 2 * maxVal; wherePush <= power - curPower; ++wherePush) {
        if (peaceAmount[curPower][maxVal] != 0) {
          peaceAmount[wherePush + curPower][wherePush] += peaceAmount[curPower][maxVal];
          peaceAmount[0][0] = 1;
        }
      }
    }
  }

  int64_t ans = 0;
  for (int maxVal = 0; maxVal <= power; ++maxVal) {
    ans += peaceAmount[power][maxVal];
  }
  std::cout << ans;
}
