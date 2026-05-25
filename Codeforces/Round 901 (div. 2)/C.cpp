#include <bits/stdc++.h>

class TestCase
{
public:
    void solve()
    {
        std::cin >> n >> m;
        int mod = n % m;

        if (mod == 0)
        {
            std::cout << 0 << '\n';
            return;
        }

        int tmod = (mod >> __builtin_ctz(mod)), tm = (m >> __builtin_ctz(m));
        if (tmod % tm != 0)
        {
            std::cout << -1 << '\n';
            return;
        }

        int64_t result = 0;
        while (mod)
        {
            result += mod;
            mod = (mod << 1) % m;
        }
        std::cout << result << '\n';
    }

private:
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
