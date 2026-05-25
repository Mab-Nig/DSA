#include <bits/stdc++.h>

#define MULTI_TEST_CASE 1

class TestCase
{
public:
    void solve()
    {
        std::cin >> n;
        a.resize(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> a[i];
        }

        a[0] = 0;
        std::sort(a.begin() + 1, a.end());
        bool is_alice = 1;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] - a[i - 1] > 1)
            {
                std::cout << (is_alice ? "Alice\n" : "Bob\n");
                return;
            }

            if (a[i] != a[i - 1])
            {
                is_alice = !is_alice;
            }
        }
        std::cout << (is_alice ? "Bob\n" : "Alice\n");
    }

private:
    int n;
    std::vector<int> a;
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
