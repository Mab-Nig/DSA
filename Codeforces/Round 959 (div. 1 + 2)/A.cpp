#include <bits/stdc++.h>

#define MULTI_TEST_CASE 1
#define a(i, j)         a[(i) * m + (j)]

class TestCase
{
public:
    void solve()
    {
        std::cin >> n >> m;
        a.resize(n * m);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                std::cin >> a(i, j);
            }
        }

        if (n * m == 1)
        {
            std::cout << -1 << '\n';
            return;
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                std::cout << (a(i, j) == n * m ? 1 : a(i, j) + 1) << ' ';
            }
            std::cout << '\n';
        }
    }

private:
    int n, m;
    std::vector<int> a;
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
