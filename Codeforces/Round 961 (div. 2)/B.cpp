#include <bits/stdc++.h>

#define MULTI_TEST_CASE 1

class TestCase
{
public:
    void solve()
    {
        std::cin >> n >> m;
        a.resize(n);
        for (int &x : a)
        {
            std::cin >> x;
        }

        std::map<int, int> cnt;
        for (int x : a)
        {
            ++cnt[x];
        }

        int64_t res = 0;
        for (auto it = cnt.begin(); it != cnt.end(); ++it)
        {
            auto next_it = std::next(it);

            res = std::max(1LL * res, 1LL * it->first
                                          * std::min(1LL * it->second,
                                                     1LL * m / it->first));

            if (next_it == cnt.end())
            {
                break;
            }

            if (it->first + 1 != next_it->first)
            {
                continue;
            }

            for (int i = 1;
                 i <= std::min(1LL * it->second, 1LL * m / it->first); ++i)
            {
                int64_t tmp =
                    std::min(1LL * next_it->second,
                             1LL * (m - 1LL * i * it->first) / next_it->first);
                res = std::max(1LL * res,
                               1LL * i * it->first + tmp * next_it->first);
            }
        }
        std::cout << res << '\n';
    }

private:
    int n;
    int64_t m;
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
