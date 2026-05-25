#include <bits/stdc++.h>

#define MULTI_TEST_CASE 1

class TestCase
{
public:
    void solve()
    {
        std::cin >> n >> m;
        a.resize(n);
        for (int i = 0; i < n; ++i)
        {
            std::cin >> a[i];
        }

        int w[4], b[4];
        w[0] = b[0] = n;
        w[2] = b[2] = m;
        w[1] = b[1] = w[3] = b[3] = -1;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (a[i][j] == 'W')
                {
                    minimize(w[0], i);
                    maximize(w[1], i);
                    minimize(w[2], j);
                    maximize(w[3], j);
                }
                if (a[i][j] == 'B')
                {
                    minimize(b[0], i);
                    maximize(b[1], i);
                    minimize(b[2], j);
                    maximize(b[3], j);
                }
            }
        }
        std::cout << (std::max(1LL * (w[1] - w[0] + 1) * (w[3] - w[2] + 1),
                               1LL * (b[1] - b[0] + 1) * (b[3] - b[2] + 1))
                              == 1LL * n * m
                          ? "YES\n"
                          : "NO\n");
    }

private:
    template <class T>
    void minimize(T& a, T const& b)
    {
        a = std::min(a, b);
    }

    template <class T>
    void maximize(T& a, T const& b)
    {
        a = std::max(a, b);
    }

private:
    int n, m;
    std::vector<std::string> a;
};

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);

    if (!MULTI_TEST_CASE)
    {
        TestCase test_case;
        test_case.solve();
        return 0;
    }

    int t;
    std::cin >> t;
    while (t--)
    {
        TestCase test_case;
        test_case.solve();
    }
}
