#include <bits/stdc++.h>

class Solution {
public:
  std::vector<int> numMovesStonesII(std::vector<int>& stones) {
    std::sort(stones.begin(), stones.end());
    std::vector<int> res = {find_min(stones), find_max(stones)};
    return res;
  }

private:
  int find_max(std::vector<int>& stones) {
    int n = stones.size();
    int sum = 0;
    int min_space =
        std::min(stones[n - 1] - stones[n - 2] - 1, stones[1] - stones[0] - 1);

    for (int i = 0; i < n - 1; ++i) {
      int space = stones[i + 1] - stones[i] - 1;
      sum += space;
    }

    return sum - min_space;
  }

  int find_min(std::vector<int>& stones) {
    int n = stones.size();
    int res = INT_MAX;
    int len = 1, l = 0;

    for (int r = 1; r < n; ++r) {
      len += stones[r] - stones[r - 1];

      while (l < r && len >= n) {
        int curr_res = n - (r - l) - (len == n);
        curr_res += ()
        res = std::min(res, curr_res);
        std::cout << l << ' ' << r << ' ' << len << ' ' << curr_res << '\n';

        len -= stones[l + 1] - stones[l];
        ++l;
      }
    }

    return res;
  }
};

int main(void) {
  std::vector<int> tests[] = {
      // {7, 4, 9},
      {6, 5, 4, 3, 10}
  };
  Solution sol;

  for (auto& test : tests) {
    auto result = sol.numMovesStonesII(test);
    std::cout << result[0] << ' ' << result[1] << '\n';
  }
}
