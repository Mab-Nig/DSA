#include <bits/stdc++.h>

#define MAXN 100

int t, n, a[MAXN];

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> t;
  while (t--) {
    bool is_non_dec = 1;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
      if (i > 0 && a[i] < a[i - 1]) {
        is_non_dec = 0;
      }
    }
    std::cout << (is_non_dec ? n : 1) << '\n';
  }
}
