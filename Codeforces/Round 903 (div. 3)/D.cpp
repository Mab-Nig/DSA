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

        std::vector<int> f(n + 2, -1);
        f[n + 1] = 0;
        for (int i = n; i > 0; --i)
        {
            f[i] = f[i + 1] + 1;
            if (i + a[i] <= n)
            {
                minimize(f[i], f[i + a[i] + 1]);
            }
        }
        std::cout << f[1] << '\n';
    }

private:
    template <class T>
    void minimize(T &a, T const &b)
    {
        a = std::min(a, b);
    }

    int n;
    std::vector<int> a;
};

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    {
        TestCase test_case;
        test_case.solve();
    }
}
