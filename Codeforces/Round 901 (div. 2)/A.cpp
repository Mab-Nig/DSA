#include <bits/stdc++.h>
#include <cstdint>
#include <unistd.h>

class TestCase
{
public:
    void solve()
    {
        std::cin >> a >> b >> n;
        x.resize(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> x[i];
        }
        std::sort(x.begin() + 1, x.end());

        int64_t result = 0, curr_timer = b;
        int tool_idx = 1;
        while (curr_timer > 0)
        {
            if (curr_timer > 1)
            {
                result += curr_timer - 1;
                curr_timer = 1;
                continue;
            }

            if (tool_idx <= n)
            {
                curr_timer += x[tool_idx++];
                if (curr_timer > a)
                {
                    curr_timer = a;
                }
            }
            --curr_timer;
            ++result;
        }
        std::cout << result << '\n';
    }

private:
    int a, b, n;
    std::vector<int> x;
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
