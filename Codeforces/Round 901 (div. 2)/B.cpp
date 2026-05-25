#include <bits/stdc++.h>
#include <cstdint>

class TestCase
{
public:
    void solve()
    {
        std::cin >> n >> m >> k;
        a.resize(n + 1);
        b.resize(m + 1);
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> a[i];
        }
        for (int i = 1; i <= m; ++i)
        {
            std::cin >> b[i];
        }
        std::sort(a.begin() + 1, a.end());
        std::sort(b.begin() + 1, b.end());

        int64_t sum_a = 0;
        for (int i = 1; i <= n; ++i)
        {
            sum_a += a[i];
        }

        std::cout << sum_a + diff_min() + diff_max() << '\n';
    }

private:
    int diff_min()
    {
        if (a[1] <= b[1])
        {
            return (k & 1) ? -a[1] : 0;
        }

        return (a[1] > b[m] ? 0 : -a[1]) + (!(k & 1) ? b[1] : 0);
    }

    int diff_max()
    {
        if (a[n] <= b[m])
        {
            return (k & 1) ? b[m] : 0;
        }

        return (a[1] > b[m] ? 0 : b[m]) + (!(k & 1) ? -a[n] : 0);
    }

    template <class T>
    void minimize(T &a, T const &b)
    {
        a = std::min(a, b);
    }

    template <class T>
    void maximize(T &a, T const &b)
    {
        a = std::max(a, b);
    }

    int n, m, k;
    std::vector<int> a, b;
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
