#include <bits/stdc++.h>

class TestCase
{
public:
    void solve()
    {
        std::cin >> n >> s;

        int64_t result = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                int k = i;
                while (k <= j)
                {
                    while (k <= j && s[k] == '0')
                    {
                        ++k;
                    }
                    while (k <= j && s[k] == '1')
                    {
                        k += 3;
                        ++result;
                    }
                }
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
