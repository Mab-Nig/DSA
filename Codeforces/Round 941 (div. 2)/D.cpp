#include <bits/stdc++.h>

#define MULTI_TEST_CASE 1

class TestCase
{
public:
    void solve()
    {
        std::cin >> n >> k;

        std::vector<int> result(32 - __builtin_clz(n));
        for (int i = 0; i < result.size(); ++i)
        {
            result[i] = (1 << i);
        }
        int k_idx = 32 - __builtin_clz(k) - 1;
        result[k_idx] -= (1 << (k_idx + 1)) - k;
        for (int i = k_idx + 1, lim = result.size(); i < lim; ++i)
        {
            result.push_back(result[i] + k);
        }
        result.push_back(k + 1);

        print(result);
    }

private:
    void print(std::vector<int> const& arr)
    {
        std::cout << arr.size() << '\n';
        for (int x : arr)
        {
            std::cout << x << ' ';
        }
        std::cout << '\n';
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
