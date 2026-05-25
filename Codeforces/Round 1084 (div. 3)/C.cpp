#include <bits/stdc++.h>

#define MAXN 5000

int t, n;
char stk[MAXN];
std::string s;

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(nullptr);

  std::cin >> t;
  while (t--) {
    std::cin >> n >> s;

    int stk_sz = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (i == 0 || s[i] != s[i - 1]) {
        cnt = 1;
      } else {
        ++cnt;
      }
      
      if (i == n - 1 || s[i] != s[i + 1]) {
        if (!(cnt & 1)) {
          continue;
        }

        if (stk_sz > 0 && stk[stk_sz - 1] == s[i]) {
          --stk_sz;
        } else {
          stk[stk_sz++] = s[i];
        }
      }
    }
    std::cout << (stk_sz ? "NO" : "YES") << '\n';
  }
}
