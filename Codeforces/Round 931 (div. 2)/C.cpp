#include <bits/stdc++.h>

class TestCase
{
public:
    void solve()
    {
        std::cin >> n >> m;

        int val = query(1, 1);

        if (val == 0)
        {
            std::cout << "! 1 1" << std::endl;
            return;
        }

        ii left = {1, 1}, right = {1, 1};
        if (1 + val <= n)
        {
            left.first = 1 + val;
        }
        else
        {
            left = std::make_pair(n, 2 + val - n);
        }

        if (1 + val <= m)
        {
            right.second = 1 + val;
        }
        else
        {
            right = std::make_pair(2 + val - m, m);
        }

        val = query(left.first, left.second);

        if (val == 0)
        {
            std::cout << "! " << left.first << ' ' << left.second << std::endl;
            return;
        }

        left.first -= val >> 1;
        left.second += (val + 1) >> 1;

        val = query(right.first, right.second);

        if (val == 0)
        {
            std::cout << "! " << right.first << ' ' << right.second
                      << std::endl;
            return;
        }

        right.first += (val + 1) >> 1;
        right.second -= val >> 1;

        if (left == right || query(left.first, left.second) == 0)
        {
            std::cout << "! " << left.first << ' ' << left.second << std::endl;
            return;
        }

        std::cout << "! " << right.first << ' ' << right.second << std::endl;
    }

private:
    using ii = std::pair<int, int>;

    int query(int i, int j)
    {
        std::cout << "? " << i << ' ' << j << std::endl;
        int result;
        std::cin >> result;
        return result;
    }

    int n, m;
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
