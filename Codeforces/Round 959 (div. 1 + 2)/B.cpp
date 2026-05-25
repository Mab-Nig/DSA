#include <bits/stdc++.h>

#define MULTI_TEST_CASE 1

class TestCase
{
public:
    void solve()
    {
        std::cin >> n >> s >> t;
        bool has_one = 0;
        for (int i = 0; i < n; ++i)
        {
            has_one |= (s[i] == '1');

            if (s[i] != t[i] && !has_one)
            {
                std::cout << "NO\n";
                return;
            }
        }
        std::cout << "YES\n";
    }

private:
    int n;
    std::string s, t;
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
