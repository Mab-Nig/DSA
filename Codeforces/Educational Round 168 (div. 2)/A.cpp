#include <bits/stdc++.h>

#define MULTI_TEST_CASE 1

class TestCase
{
public:
    void solve()
    {
        std::cin >> s;
        int n = s.size();

        int res = 0, same_pos = -1;
        for (int i = 0; i < n; ++i)
        {
            res += (i == 0 || s[i] == s[i - 1] ? 2 : 1);
            if (i > 0 && s[i] == s[i - 1])
            {
                same_pos = i;
            }
        }

        if (same_pos == -1)
        {
            std::cout << s + next(s.back()) << '\n';
        }
        else
        {
            std::cout << s.substr(0, same_pos) + next(s[same_pos])
                             + s.substr(same_pos, n - same_pos)
                      << '\n';
        }
    }

private:
    char next(char c)
    {
        return 'a' + (c - 'a' + 1) % 26;
    }

private:
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
