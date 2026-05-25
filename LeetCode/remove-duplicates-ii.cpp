#include <bits/stdc++.h>

class Solution {
public:
  std::string removeDuplicates(std::string s, int k) {
    std::vector<int> stk, cnt_cons((size_t)1e5);
    stk.reserve(1e5);

    for (int i = 0; i < s.size(); ++i) {
      if (stk.empty() || s[i] != s[stk.back()]) {
        cnt_cons[i] = 1;
        stk.push_back(i);
        continue;
      }

      if (cnt_cons[stk.back()] == k - 1) {
        while (!stk.empty() && s[stk.back()] == s[i]) {
          stk.pop_back();
        }
      } else {
        cnt_cons[i] = cnt_cons[stk.back()] + 1;
        stk.push_back(i);
      }
    }

    std::string result;
    result.reserve(stk.size());
    for (int idx : stk) {
      result += s[idx];
    }
    return result;
  }
};

int main() {
  const std::pair<const char *, int> inputs[] = {
    {"abcd",                 2},
    {"deeedbbcccbdaa",       3},
    {"pbbcggttciiippooaais", 2}
  };
  Solution sol;
  for (const auto &input : inputs) {
    std::cout << sol.removeDuplicates(input.first, input.second) << '\n';
  }
}
