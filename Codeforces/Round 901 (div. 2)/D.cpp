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

        std::vector<int> cnts(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] <= n)
            {
                ++cnts[a[i]];
            }
        }

        int mex = n;
        for (int i = 0; i < n; ++i)
        {
            if (cnts[i] == 0)
            {
                mex = i;
                break;
            }
        }

        std::vector<int64_t> f(n + 1, LLONG_MAX);
        f[mex] = 0;
        for (int i = mex - 1; i >= 0; --i)
        {
            for (int j = i + 1; j <= mex; ++j)
            {
                minimize(f[i], f[j] + j * (cnts[i] - 1) + i);
            }
        }
        std::cout << f[0] << '\n';
    }

private:
    template <class T>
    void minimize(T &a, T const &b)
    {
        a = std::min(a, b);
    }

    template <class T>
    void print(std::vector<T> const &vec, int first, int last)
    {
        for (int i = first; i <= last; ++i)
        {
            std::cerr << vec[i] << ' ';
        }
        std::cerr << '\n';
    }

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
