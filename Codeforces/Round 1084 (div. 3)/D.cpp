#include <bits/stdc++.h>

#define MAXN 200000

int t, n, x, y, p[MAXN + 1];

void print_mid(int min_mid_idx) {
  for (int i = min_mid_idx; i <= y; ++i) {
    std::cout << p[i] << ' ';
  }
  for (int i = x + 1; i < min_mid_idx; ++i) {
    std::cout << p[i] << ' ';
  }
}

void print_forehead(int mv_head_idx) {
  for (int i = 1; i < mv_head_idx; ++i) {
    std::cout << p[i] << ' ';
  }
}

void print_backhead(int mv_head_idx) {
  for (int i = mv_head_idx; i <= x; ++i) {
    std::cout << p[i] << ' ';
  }
}

void print_foretail(int mv_tail_idx) {
  for (int i = y + 1; i < mv_tail_idx; ++i) {
    std::cout << p[i] << ' ';
  }
}

void print_backtail(int mv_tail_idx) {
  for (int i = mv_tail_idx; i <= n; ++i) {
    std::cout << p[i] << ' ';
  }
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(nullptr);

  std::cin >> t;
  while (t--) {
    std::cin >> n >> x >> y;
    for (int i = 1; i <= n; ++i) {
      std::cin >> p[i];
    }

    int min_mid_idx = x + 1;
    for (int i = x + 2; i <= y; ++i) {
      if (p[i] < p[min_mid_idx]) {
        min_mid_idx = i;
      }
    }

    int mv_head_idx = 1, mv_tail_idx = y + 1;
    while (mv_head_idx <= x && p[mv_head_idx] <= p[min_mid_idx]) {
      ++mv_head_idx;
    }
    while (mv_tail_idx <= n && p[mv_tail_idx] <= p[min_mid_idx]) {
      ++mv_tail_idx;
    }
    // std::cerr << mv_head_idx << ' ' << min_mid_idx << ' ' << mv_tail_idx
    //           << '\n';

    print_forehead(mv_head_idx);
    if (mv_head_idx <= x) {
      print_mid(min_mid_idx);
      print_backhead(mv_head_idx);
      print_foretail(mv_tail_idx);
      print_backtail(mv_tail_idx);
    } else {
      print_backhead(mv_head_idx);
      print_foretail(mv_tail_idx);
      print_mid(min_mid_idx);
      print_backtail(mv_tail_idx);
    }
    std::cout << '\n';
  }
}
