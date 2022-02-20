#include <iostream>
#include <vector>

int main() {
  int bagSize = 0;
  int num = 0;
  std::cin >> bagSize >> num;
  std::vector<int> wight;
  for (int i = 0; i < num; ++i) {
    int help = 0;
    std::cin >> help;
    wight.push_back(help);
  }
  std::vector<std::vector<int>> maxWeight(num+1, std::vector<int>(bagSize+1));
  for (int chosen = 1; chosen <= num; ++chosen) {
    for (int curSize = 1; curSize <= bagSize; ++curSize) {
      if (curSize >= wight[chosen-1]) {
        maxWeight[chosen][curSize] = std::max(maxWeight[chosen - 1][curSize],
                                              maxWeight[chosen - 1][curSize - wight[chosen - 1]] + wight[chosen - 1]);
      }
      else {
        maxWeight[chosen][curSize] = maxWeight[chosen - 1][curSize];
      }
    }

  }
  std::cout << maxWeight[num][bagSize];
}
