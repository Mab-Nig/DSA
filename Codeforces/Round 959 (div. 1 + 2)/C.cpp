#include <bits/stdc++.h>

#define MULTI_TEST_CASE 1

class TestCase
{
public:
    void solve()
    {
        std::cin >> n >> x;
        a.resize(n);
        for (int& x : a)
        {
            std::cin >> x;
        }

        std::vector<int64_t> f(n, 0);
        int j = n - 1;
        int64_t sum = 0, res = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            sum += a[i];
            while (i <= j && sum > x)
            {
                sum -= a[j];
                --j;
            }
            f[i] = j - i + 1;
            if (j + 2 < n)
            {
                f[i] += f[j + 2];
            }
            res += f[i];
        }
        std::cout << res << '\n';
    }

private:
    int n, x;
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
