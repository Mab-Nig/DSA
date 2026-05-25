#include <bits/stdc++.h>

class TestCase
{
public:
    void solve()
    {
        std::cin >> n;

        int result = 0, mod_3 = n % 3;
        for (int i = 1; i <= mod_3; ++i)
        {
            ++result;
            n -= (n >= 10 ? 10 : 1);
        }
        result += n / 15;
        n %= 15;
        result += n / 6;
        n %= 6;
        result += n / 3;
        std::cout << result << '\n';
    }

private:
    int n;
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
