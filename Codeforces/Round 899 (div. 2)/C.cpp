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

        int64_t result = 0;
        for (int i = 1; i <= n; ++i)
        {
            result += std::max(a[i], 0);
        }
        if (n >= 2 && a[1] < 0 && a[2] >= 0)
        {
            result += (a[1] + a[2] >= 0 ? a[1] : -a[2]);
        }
        std::cout << result << '\n';
    }

private:
    int n;
    std::vector<int> a;
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
