#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int firstLen, secondLen;
  std::cin >> firstLen;
  std::vector<int> first;
  for (int i = 0; i < firstLen; ++i) {
    int input;
    std::cin >> input;
    first.push_back(input);
  }
  std::vector<int> second;
  std::cin >> secondLen;
  for (int i = 0; i < secondLen; ++i) {
    int input;
    std::cin >> input;
    second.push_back(input);
  }

  std::vector<std::vector<int>> subMax(firstLen+1, std::vector<int>(2));
  int cur = 1;
  int prev = 0;
  for (int count2 = 1; count2 <= secondLen; ++count2) {
    cur = prev;
    prev = (prev + 1) % 2;
    for (int count1 = 1; count1 <= firstLen; ++count1) {
      if (first[count1-1] == second[count2-1]) {
        subMax[count1][cur] = std::max(subMax[count1-1][cur], std::max(subMax[count1][prev], subMax[count1-1][prev]+1) );
      }
      else {
        subMax[count1][cur] = std::max(subMax[count1-1][cur], subMax[count1][prev]);
      }
    }
  }
  std::cout << subMax[firstLen][cur];
}
