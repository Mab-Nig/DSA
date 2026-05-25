#include <bits/stdc++.h>

#define MULTI_TEST_CASE 1

class TestCase
{
public:
    void solve()
    {
        std::cin >> n;
        free[0].resize(n);
        free[1].resize(n);
        for (int i = 0; i <= 1; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                char c;
                std::cin >> c;
                free[i][j] = (c == '.');
            }
        }

        int res = 0;
        for (int j = 1; j + 1 < n; ++j)
        {
            if (free[0][j] && free[0][j - 1] && free[0][j + 1] && free[1][j]
                && !free[1][j - 1] && !free[1][j + 1])
            {
                ++res;
            }
            if (free[1][j] && free[1][j - 1] && free[1][j + 1] && free[0][j]
                && !free[0][j - 1] && !free[0][j + 1])
            {
                ++res;
            }
        }
        std::cout << res << '\n';
    }

private:
    int n;
    std::vector<int> free[2];
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
