#include <bits/stdc++.h>

class Solution {
public:
  int evalRPN(const std::vector<std::string> &tokens) {
    std::vector<int> stk;
    stk.reserve(1e4);
    for (const auto &token : tokens) {
      if (token.size() > 1 || (token[0] >= '0' && token[0] <= '9')) {
        stk.push_back(std::stoi(token));
        continue;
      }

      int rhs = stk.back();
      stk.pop_back();
      int lhs = stk.back();
      stk.pop_back();

      int result;
      switch (token[0]) {
      case '+':
        result = lhs + rhs;
        break;
      case '-':
        result = lhs - rhs;
        break;
      case '*':
        result = lhs * rhs;
        break;
      case '/':
        result = lhs / rhs;
        break;
      }

      stk.push_back(result);
    }
    return stk[0];
  }
};

int main() {
  const std::vector<std::string> inputs[] = {
    {"2", "1", "+", "3", "*"},
    {"4", "13", "5", "/", "+"},
    {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}
  };
  Solution sol;
  for (const auto &input : inputs) {
    std::cout << sol.evalRPN(input) << '\n';
  }
}
