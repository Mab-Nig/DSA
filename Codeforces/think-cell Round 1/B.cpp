#include <bits/stdc++.h>

class TestCase
{
public:
    void solve()
    {
        std::cin >> n;

        int i = 1, j = n;
        while (i <= j)
        {
            if (i == j)
            {
                std::cout << i << ' ';
                break;
            }

            std::cout << i++ << ' ' << j-- << ' ';
        }
        std::cout << '\n';
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
