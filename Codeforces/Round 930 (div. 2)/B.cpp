#include <bits/stdc++.h>

class TestCase
{
public:
    void solve()
    {
        std::cin >> n >> a[0] >> a[1];

        std::vector<int8_t> cmps(n);
        for (int i = 0; i < n - 1; ++i)
        {
            if (i == 0 || cmps[i - 1] <= 0)
            {
                cmps[i] = compare(a[0][i + 1], a[1][i]);
                continue;
            }

            cmps[i] = 1;
        }

        std::string result;
        int result_cnt = 1;
        for (int i = n - 1; i >= 0; --i)
        {
            if ((i == 0 || cmps[i - 1] <= 0) && result.empty())
            {
                for (int j = 0; j <= i; ++j)
                {
                    result += a[0][j];
                }

                for (int j = i; j < n; ++j)
                {
                    result += a[1][j];
                }
            }

            if (i == 0 || cmps[i - 1] == -1)
            {
                break;
            }

            if (cmps[i - 1] == 0)
            {
                ++result_cnt;
            }
        }
        std::cout << result << '\n' << result_cnt << '\n';
    }

private:
    int8_t compare(char a, char b)
    {
        return a < b ? -1 : (a == b ? 0 : 1);
    }

    int n;
    std::string a[2];
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
