#include <bits/stdc++.h>

#define MULTI_TEST_CASE 1

class TestCase
{
public:
    void solve()
    {
        std::cin >> n >> m;

        int64_t result = 0;
        for (int p = 1; p * p <= n; ++p)
        {
            for (int q = 1; q * q <= m; ++q)
            {
                if (std::__gcd(p, q) > 1)
                {
                    continue;
                }

                result += std::min(n / p, m / q) / (p + q);
            }
        }
        std::cout << result << '\n';
    }

private:
    int n, m;
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
