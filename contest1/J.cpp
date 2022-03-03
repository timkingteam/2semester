#include <iostream>
#include <vector>

const int64_t module = 1000000007;

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> value(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> value[i];
  }

  std::vector<int64_t> endInI(2000000);
  int64_t ans = 1;
  int64_t withoutI = 0;
  for (int i = 0; i < n; ++i) {
    withoutI = (ans - endInI[value[i]] ) % module;
    if (withoutI < 0) {
      withoutI = module + withoutI;
    }
    endInI[value[i]] = ans;
    ans = ( ans + withoutI ) % module;
  }
  std::cout << ( ans - 1 ) % module;
}

