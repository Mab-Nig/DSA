#include <bits/stdc++.h>

#define MULTI_TEST_CASE 1

class TestCase
{
public:
    void solve()
    {
        std::cin >> n >> k;
        a.resize(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> a[i];
        }

        int64_t result = 0;
        std::sort(a.begin() + 1, a.end());
        result += a[1] * n - n + 1;
        for (int i = 2; i <= n; ++i)
        {
            if (a[i] == a[i - 1])
            {
                continue;
            }

            if (k / (i - 1) < a[i] - a[i - 1])
            {
                result += k / (i - 1) * n;
                result += k % (i - 1) + n - i + 1;
                k = 0;
                break;
            }

            int64_t layer_cnt = std::min(k / (i - 1), a[i] - a[i - 1]);
            result += layer_cnt * n;
            k -= layer_cnt * (i - 1);
        }
        result += k;
        std::cout << result << '\n';
    }

private:
    void print(std::vector<int> const& arr)
    {
        for (int i = 1; i <= n; ++i)
        {
            std::cerr << arr[i] << ' ';
        }
        std::cerr << '\n';
    }

private:
    int n;
    int64_t k;
    std::vector<int64_t> a;
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
