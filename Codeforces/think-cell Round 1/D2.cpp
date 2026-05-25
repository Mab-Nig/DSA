#include <bits/stdc++.h>

class TestCase
{
public:
    void solve()
    {
        std::cin >> n >> s;

        std::vector<int> start_cnt(n, 1);
        for (int i = 0; i < n; ++i)
        {
            if (i >= 1 && s[i - 1] == '0')
            {
                start_cnt[i] += start_cnt[i - 1];
            }
            if (i >= 3 && s[i - 3] == '1')
            {
                start_cnt[i] += start_cnt[i - 3];
            }
        }

        int64_t result = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '1')
            {
                result += 1LL * start_cnt[i] * (n - i);
            }
        }
        std::cout << result << '\n';
    }

private:
    int n;
    std::string s;
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
