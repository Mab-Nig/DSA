#include <bits/stdc++.h>

class Solution {
public:  
  int getLastMoment(
    int n, const std::vector<int> &left, const std::vector<int> &right
  ) {
    int max_left = 0, min_right = n;
    for (int val : left) {
      max_left = std::max(max_left, val);
    }
    for (int val : right) {
      min_right = std::min(min_right, val);
    }
    return std::max(max_left, n - min_right);
  }
};

int main() {
  Solution sol;
  std::cout << sol.getLastMoment(4, {4, 3}, {0, 1}) << '\n';
}
