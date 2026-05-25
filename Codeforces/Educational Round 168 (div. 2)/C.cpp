#include <bits/stdc++.h>

#define MULTI_TEST_CASE 1

class TestCase
{
public:
    void solve()
    {
        std::cin >> n >> s;

        int res = 0, open_pos = 0;
        for (int i = 1; i < n; i += 2)
        {
            if (s[i] == '(')
            {
                s[i + 1] = ')';
                ++res;
                continue;
            }

            s[open_pos] = '(';
            res += i - open_pos;
            open_pos = i + 1;
        }
        // std::cerr << s << '\n';
        std::cout << res << '\n';
    }

private:
    int n;
    std::string s;
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
