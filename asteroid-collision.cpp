#include <bits/stdc++.h>

class Solution {
public:
  std::vector<int> asteroidCollision(const std::vector<int>& asteroids) {
    std::vector<int> posi, nega;
    posi.reserve(1e4);
    nega.reserve(2e4);

    for (int ast : asteroids) {
      if (ast > 0) {
        posi.push_back(ast);
        continue;
      }

      while (!posi.empty() && -ast > posi.back()) {
        posi.pop_back();
      }
      if (posi.empty()) {
        nega.push_back(ast);
      } else if (-ast == posi.back()) {
        posi.pop_back();
      }
    }

    nega.insert(nega.end(), posi.begin(), posi.end());
    return nega;
  }
};

std::ostream &operator<<(std::ostream &os, const std::vector<int> &vec) {
  for (int val : vec) {
    os << val << ' ';
  }
  return os;
}

int main() {
  const std::vector<int> inputs[] = {
    {5, 10, -5},
    {8, -8},
    {10, 2, -5},
    {3, 5, -6, 2, -1, 4}
  };
  Solution sol;
  for (const auto &input : inputs) {
    std::cout << sol.asteroidCollision(input) << '\n';
  }
}
