#include <bits/stdc++.h>

#define MAXN           30
#define MAX_SUM        (100000LL * MAXN)
#define NCOL           (MAX_SUM * 2 + 1)
#define SAVE(idx, sum) save[(idx) * NCOL + (sum) + MAX_SUM]

class Solution {
public:
  bool splitArraySameAverage(std::vector<int> &nums) {
    int n = nums.size();

    if (n <= 1) {
      return 0;
    }

    save.resize(MAXN * NCOL, 0);

    int sum = std::reduce(nums.begin(), nums.end());
    for (int i = 0; i < n; ++i) {
      nums[i] = nums[i] * n - sum;
    }
    for (int i = 0; i < n; ++i) {
      dp(nums, i, nums[i]);
    }
    return SAVE(n - 2, 0);
  }

private:
  void dp(const std::vector<int> &nums, int idx, int sum) {
    if (SAVE(idx, sum)) {
      return;
    }

    int n = nums.size();

    SAVE(idx, sum) = 1;
    if (idx < n - 1) {
      dp(nums, idx + 1, sum);
      dp(nums, idx + 1, sum + nums[idx + 1]);
    }
  }

private:
  std::vector<bool> save;
};

int main(void) {
  std::vector<int> tests[] = {
    {1, 2, 3, 4, 5, 6, 7, 8},
    {3, 1},
    {12, 1, 17, 8, 2},
    {3863, 703, 1799, 327,  3682, 4330, 3388, 6187, 5330,
     6572, 938, 6842, 678,  9837, 8256, 6886, 2204, 5262,
     6643, 829, 745,  8755, 3549, 6627, 1633, 4290, 7},
    {83, 71, 2}
  };
  Solution sol;
  for (auto &test : tests) {
    std::cout << sol.splitArraySameAverage(test) << '\n';
  }
}
