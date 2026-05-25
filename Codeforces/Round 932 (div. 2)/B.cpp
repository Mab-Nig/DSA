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

        int mex;
        {
            std::vector<int> ta(std::next(a.begin()), a.end());
            mex = find_mex(ta.begin(), ta.end());
        }

        std::set<int> set;
        int curr_mex = 0;
        int i = 1;
        for (; i <= n; ++i)
        {
            if (a[i] < curr_mex)
            {
                continue;
            }

            set.emplace(a[i]);
            while (!set.empty() && *set.begin() == curr_mex)
            {
                ++curr_mex;
                set.erase(set.begin());
            }

            if (curr_mex == mex)
            {
                break;
            }
        }

        if (i == n || find_mex(std::next(a.begin(), i + 1), a.end()) != mex)
        {
            std::cout << -1 << '\n';
            return;
        }

        std::cout << 2 << '\n';
        std::cout << 1 << ' ' << i << '\n' << i + 1 << ' ' << n << '\n';
    }

private:
    int find_mex(std::vector<int>::iterator first,
                 std::vector<int>::iterator last)
    {
        std::sort(first, last);
        int result = 0;
        for (auto it = first; it != last && *it <= result; ++it)
        {
            if (*it == result)
            {
                ++result;
            }
        }
        return result;
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
