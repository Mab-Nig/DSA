#include <bits/stdc++.h>

class TestCase
{
public:
#define CELL(i, j) ((i) * (n + 1) + (j))

    void solve()
    {
        std::cin >> n;
        a.resize((n + 1) * (n + 1));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                std::cin >> a[CELL(i, j)];
            }
        }

        int64_t result = 0;
        for (int i = 1; i <= (n >> 1); ++i)
        {
            for (int j = 1; j <= (n >> 1); ++j)
            {
                std::array<char, 4> arr;
                int dx = i - (n >> 1), dy = j - (n >> 1);
                arr[0] = a[CELL(i, j)];
                arr[1] = a[CELL((n >> 1) + dy, (n >> 1) + 1 - dx)];
                arr[2] = a[CELL((n >> 1) + 1 - dx, (n >> 1) + 1 - dy)];
                arr[3] = a[CELL((n >> 1) + 1 - dy, (n >> 1) + dx)];
                result += calc_cost(arr);
            }
        }
        std::cout << result << '\n';
    }

private:
    int calc_cost(std::array<char, 4> arr)
    {
        char max = std::max({arr[0], arr[1], arr[2], arr[3]});
        return 4 * max - arr[3] - arr[2] - arr[1] - arr[0];
    }

    int n;
    std::vector<char> a;
};

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    {
        TestCase test_case;
        test_case.solve();
    }
}
