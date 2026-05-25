#include <bits/stdc++.h>

class TestCase
{
public:
    void solve()
    {
        std::cin >> n;
        a.resize((n << 1) + 1);
        for (int i = 1; i <= (n << 1); ++i)
        {
            std::cin >> a[i];
        }
        std::sort(std::next(a.begin()), a.end());

        int result = 0;
        for (int i = 1; i <= (n << 1); i += 2)
        {
            result += a[i];
        }
        std::cout << result << '\n';
    }

private:
    int n;
    std::vector<int> a;
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
