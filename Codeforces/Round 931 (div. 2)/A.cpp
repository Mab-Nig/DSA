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
        std::sort(std::next(a.begin()), a.end());

        std::cout << 2LL * (a[2] - a[1] + a[n] - a[n - 1])
                         + 4LL * (a[n - 1] - a[2])
                  << '\n';
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
