#include <bits/stdc++.h>

class TestCase
{
public:
    void solve()
    {
        std::cin >> n >> m;

        if ((n & m) == m)
        {
            std::cout << 1 << '\n';
            std::cout << n << ' ' << m << '\n';
            return;
        }

        int one_zero = -1;
        for (int i = 62; i >= 0; --i)
        {
            if (bit_at_pos(n, i) && !bit_at_pos(m, i))
            {
                one_zero = i;
                break;
            }
        }

        if (one_zero == -1)
        {
            std::cout << -1 << '\n';
            return;
        }

        int64_t y = 1LL << one_zero;
        for (int i = 62; i >= 0; --i)
        {
            if (!bit_at_pos(n, i) && bit_at_pos(m, i))
            {
                y |= 1LL << i;
            }
        }

        if (y >= n || (n ^ y) >= n)
        {
            std::cout << -1 << '\n';
            return;
        }

        if ((n ^ y) == m)
        {
            std::cout << 1 << '\n';
            std::cout << n << ' ' << m << '\n';
        }
        else
        {
            std::cout << 2 << '\n';
            std::cout << n << ' ' << (n ^ y) << ' ' << m << '\n';
        }
    }

private:
    inline bool bit_at_pos(int64_t mask, int pos)
    {
        return (mask >> pos) & 1;
    }

    int64_t n, m;
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
