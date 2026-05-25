#include <bits/stdc++.h>

#define MULTI_TEST_CASE 1

class TestCase
{
public:
    void solve()
    {
        std::cin >> n >> k;
        a.resize(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> a[i];
        }

        std::unordered_map<int, int> cnts;
        for (int i = 1; i <= n; ++i)
        {
            ++cnts[a[i]];
        }
        for (auto const &[val, cnt] : cnts)
        {
            if (cnt >= k)
            {
                std::cout << k - 1 << '\n';
                return;
            }
        }
        std::cout << n << '\n';
    }

private:
    int n, k;
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
