#include <bits/stdc++.h>

class Solution {
public:
  std::vector<int> dailyTemperatures(const std::vector<int> &temperatures) {
    int n = temperatures.size();
    std::vector<int> answer(n);
    std::stack<int, std::vector<int>> stck;
    {
      std::vector<int> tmp;
      tmp.reserve(n);
      std::stack<int, std::vector<int>> tmp_stck(std::move(tmp));
      stck.swap(tmp_stck);
    }
    for (int i = n - 1; i >= 0; --i) {
      while (!stck.empty() && temperatures[stck.top()] <= temperatures[i]) {
        stck.pop();
      }
      answer[i] = stck.empty() ? 0 : stck.top() - i;
      stck.push(i);
    }
    return answer;
  }
};

std::ostream &operator<<(std::ostream &os, const std::vector<int> &nums) {
  for (int x : nums) {
    os << x << ' ';
  }
  return os;
}

int main() {
  Solution sol;
  std::vector<int> inputs[] = {
    {73, 74, 75, 71, 69, 72, 76, 73},
    {30, 40, 50, 60},
    {30, 60, 90}
  };
  for (const auto &nums : inputs) {
    std::cout << sol.dailyTemperatures(nums) << '\n';
  }
}
