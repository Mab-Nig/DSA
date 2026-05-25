#include <bits/stdc++.h>

class TestCase
{
public:
    void solve()
    {
        std::cin >> n;

        int max = 0;
        for (int i = 1; i < n; ++i)
        {
            query(max, max, i, i);
            char result;
            std::cin >> result;
            if (result == '<')
            {
                max = i;
            }
        }

        std::vector<int> max_or_idx(n);
        max_or_idx[0] = 0;
        int max_or = 0, top = 0;
        for (int i = 1; i < n; ++i)
        {
            if (i == max)
            {
                continue;
            }

            query(max, max_or, max, i);
            char result;
            std::cin >> result;
            switch (result)
            {
            case '<':
                max_or = i;
                top = 0;
                max_or_idx[0] = i;
                break;

            case '=':
                max_or_idx[++top] = i;
                break;

            default:
                break;
            }
        }

        int min_max_or = max_or_idx[0];
        for (int i = 1; i <= top; ++i)
        {
            query(min_max_or, min_max_or, max_or_idx[i], max_or_idx[i]);
            char result;
            std::cin >> result;
            if (result == '>')
            {
                min_max_or = max_or_idx[i];
            }
        }
        std::cout << "! " << max << ' ' << min_max_or << std::endl;
    }

private:
    void query(int a, int b, int c, int d)
    {
        std::cout << "? " << a << ' ' << b << ' ' << c << ' ' << d << std::endl;
    }

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
