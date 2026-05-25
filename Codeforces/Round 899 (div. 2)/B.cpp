#include <bits/stdc++.h>

class TestCase
{
public:
    void solve()
    {
        std::cin >> n;
        sets.resize(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            int k;
            std::cin >> k;
            for (int j = 1; j <= k; ++j)
            {
                int x;
                std::cin >> x;
                sets[i].set(x - 1);
            }
        }

        int result = 0;
        for (int i = 1; i <= MAXN; ++i)
        {
            bool is_i_valid = 0;
            for (int j = 1; j <= n; ++j)
            {
                if (sets[j].test(i - 1))
                {
                    is_i_valid = 1;
                    break;
                }
            }

            if (!is_i_valid)
            {
                continue;
            }

            std::bitset<MAXN> union_set;
            for (int j = 1; j <= n; ++j)
            {
                if (!sets[j].test(i - 1))
                {
                    union_set |= sets[j];
                }
            }
            maximize(result, int(union_set.count()));
        }
        std::cout << result << '\n';
    }

private:
    static constexpr int MAXN = 50;

    template <class T>
    void maximize(T &a, T const &b)
    {
        a = std::max(a, b);
    }

    int n;
    std::vector<std::bitset<MAXN>> sets;
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
