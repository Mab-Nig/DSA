#include <bits/stdc++.h>

class Solution {
public:
  void
  merge(std::vector<int> &nums1, int m, const std::vector<int> &nums2, int n) {
    int i = m - 1, j = n - 1, idx = m + n - 1;
    while (i >= 0 || j >= 0) {
      if (i < 0) {
        for (; j >= 0; --j) {
          nums1[idx--] = nums2[j];
        }
        break;
      }
      if (j < 0) {
        for (; i >= 0; --i) {
          nums1[idx--] = nums1[i];
        }
        break;
      }
      if (nums1[i] > nums2[j]) {
        nums1[idx--] = nums1[i--];
      } else {
        nums1[idx--] = nums2[j--];
      }
    }
  }
};

void print(const std::vector<int> &nums) {
  for (auto x : nums) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
}

int main() {
  struct Input {
    std::vector<int> nums1, nums2;
    int m, n;
  };

  Input inputs[] = {
    {{1, 2, 3, 0, 0, 0}, {2, 5, 6}, 3, 3}, {{1}, {}, 1, 0}, {{0}, {1}, 0, 1}
  };
  Solution sol;
  for (auto &[nums1, nums2, m, n] : inputs) {
    sol.merge(nums1, m, nums2, n);
    print(nums1);
  }
}
