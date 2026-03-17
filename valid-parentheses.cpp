#include <bits/stdc++.h>

#define MAXLEN 10000

class Solution {
public:
  bool isValid(std::string s) {
    char par_stack[MAXLEN];
    int top = 0;
    bool result = 1;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
        par_stack[top++] = s[i];
        continue;
      }
      if (!top || get_open_par(s[i]) != par_stack[top - 1]) {
        result = 0;
        break;
      }
      --top;
    }
    return result && !top;
  }

private:
  char get_open_par(char close_par) {
    switch (close_par) {
    case ')':
      return '(';
    case ']':
      return '[';
    default:
      return '{';
    }
  }
};

int main() {
  Solution sol;
  const char *inputs[] = {"()", "()[]{}", "(]", "([])", "([)]"};
  for (auto s : inputs) {
    std::cout << sol.isValid(s) << '\n';
  }
}
