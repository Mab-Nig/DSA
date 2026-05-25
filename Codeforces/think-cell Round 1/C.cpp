#include <bits/stdc++.h>

template <class T>
void maximize(T &a, T const &b)
{
    a = std::max(a, b);
}

class TestCase
{
public:
    void solve()
    {
        std::cin >> n;
        a.resize(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> a[i];
        }

        std::vector<std::pair<int, int>> val_idx;
        for (int i = 1; i <= n; ++i)
        {
            val_idx.emplace_back(a[i] + i, i);
        }
        std::sort(val_idx.begin(), val_idx.end(),
                  [](std::pair<int, int> const &a,
                     std::pair<int, int> const &b) -> bool
                  {
                      return a.first < b.first
                             || (a.first == b.first && a.second > b.second);
                  });

        int curr_val = val_idx.back().first;
        for (int i = n - 1; i >= 0; --i)
        {
            if (val_idx[i].first < curr_val)
            {
                std::cout << val_idx[i].first << ' ';
                curr_val = val_idx[i].first - 1;
                continue;
            }

            std::cout << curr_val-- << ' ';
        }
        std::cout << '\n';
    }

private:
    int n;
    std::vector<int> a;
};

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
    {
        TestCase test_case;
        test_case.solve();
    }
}
