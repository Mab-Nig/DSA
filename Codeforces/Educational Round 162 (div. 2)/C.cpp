#include <bits/stdc++.h>

class TestCase
{
public:
    void solve()
    {
        std::cin >> n >> q;
        c.resize(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> c[i];
        }

        std::vector<int64_t> pre(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            pre[i] = pre[i - 1] + c[i];
        }
        std::vector<int> ones(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            ones[i] = ones[i - 1] + (c[i] == 1);
        }

        for (int i = 1; i <= q; ++i)
        {
            int l, r;
            std::cin >> l >> r;
            std::cout << (l == r
                                  || (ones[r] - ones[l - 1]
                                      > pre[r] - pre[l - 1])
                              ? "NO\n"
                              : "YES\n");
        }
    }

private:
    int n, q;
    std::vector<int> c;
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
