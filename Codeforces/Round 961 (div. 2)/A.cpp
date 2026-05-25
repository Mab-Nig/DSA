#include <bits/stdc++.h>

#define MULTI_TEST_CASE 1

class TestCase
{
public:
    void solve()
    {
        std::cin >> n >> k;

        if (k == 0)
        {
            std::cout << 0 << '\n';
            return;
        }
        
        if (k <= n)
        {
            std::cout << 1 << '\n';
            return;
        }

        k -= n;
        int res = 1;
        for (int i = n - 1; i >= 1; --i)
        {
            ++res;
            k -= i;

            if (k <= 0)
            {
                break;
            }

            ++res;
            k -= i;

            if (k <= 0)
            {
                break;
            }
        }
        std::cout << res << '\n';
    }

private:
    int n, k;
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
