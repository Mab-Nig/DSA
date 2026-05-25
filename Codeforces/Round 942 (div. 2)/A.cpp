#include <bits/stdc++.h>

#define MULTI_TEST_CASE 1

class TestCase
{
public:
    void solve()
    {
        std::cin >> n;
        a.resize(n + 1);
        b.resize(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> a[i];
        }
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> b[i];
        }

        int result = 0;
        for (int i = 1; i + result <= n; ++i)
        {
            int j = i + result;

            if (a[i] <= b[j])
            {
                continue;
            }

            ++j;
            ++result;
            for (; j <= n && a[i] > b[j]; ++j)
            {
                ++result;
            }
        }
        std::cout << result << '\n';
    }

private:
    int n;
    std::vector<int> a, b;
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
