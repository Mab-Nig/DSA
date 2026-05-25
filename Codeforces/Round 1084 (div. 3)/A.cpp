#include <bits/stdc++.h>

#define MAXN 10

int t, n, a[MAXN];

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> t;
  while (t--) {
    int max = 0, res = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
      max = std::max(max, a[i]);
    }
    for (int i = 0; i < n; ++i) {
      res += (a[i] == max);
    }
    std::cout << res << '\n';
  }
}
