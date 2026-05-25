#include <bits/stdc++.h>

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
        std::sort(a.begin() + 1, a.end());

        appearance_cnts.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            ++appearance_cnts[a[i]];
        }

        divisor_cnts.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            if (appearance_cnts[i] == 0)
            {
                continue;
            }

            for (int j = i; j <= n; j += i)
            {
                ++divisor_cnts[j];
            }
        }

        pair_cnts.resize(n + 1, 0);
        int64_t result = 1LL * n * (n - 1) / 2;
        for (int i = n; i > 0; --i)
        {
            for (int j = i; j <= n; j += i)
            {
                pair_cnts[i] += appearance_cnts[j];
            }
            pair_cnts[i] = 1LL * pair_cnts[i] * (pair_cnts[i] - 1) / 2;
            for (int j = (i << 1); j <= n; j += i)
            {
                pair_cnts[i] -= pair_cnts[j];
            }
            if (divisor_cnts[i] > 0)
            {
                result -= pair_cnts[i];
            }
        }
        std::cout << result << '\n';
    }

private:
    void print(std::vector<int> const &nums)
    {
        for (int x : nums)
        {
            std::cerr << x << ' ';
        }
        std::cerr << '\n';
    }

    int n;
    std::vector<int> a;
    std::vector<int> appearance_cnts;
    std::vector<int> divisor_cnts;
    std::vector<int64_t> pair_cnts;
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
