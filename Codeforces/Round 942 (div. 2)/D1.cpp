#include <bits/stdc++.h>

#define MULTI_TEST_CASE 1

class TestCase
{
public:
    void solve()
    {
        std::cin >> n >> m;

        int64_t result = 0;
        for (int b = 1; b <= m && b * (b - 1) <= n; ++b)
        {
            int b_sqr = b * b;
            int lbound = b, ubound = (n + b_sqr - 1) / b_sqr * b_sqr - b;
            if (ubound > n)
            {
                ubound = n / b_sqr * b_sqr - b;
            }
            result += (ubound - lbound) / b_sqr + 1;
        }
        ++result;
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
