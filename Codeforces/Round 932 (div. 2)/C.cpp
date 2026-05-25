#include <bits/stdc++.h>

class TestCase
{
public:
    void solve()
    {
        std::cin >> n >> l;
        messages.resize(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> messages[i].first >> messages[i].second;
        }

        std::sort(std::next(messages.begin()), messages.end(),
                  [](ii const &a, ii const &b) -> bool
                  {
                      return a.second < b.second;
                  });

        int result = 0;
        for (int i = 1; i <= n; ++i)
        {
            std::priority_queue<int> nums;
            int64_t sum_a = 0;
            for (int j = i; j <= n; ++j)
            {
                sum_a += messages[j].first;
                nums.emplace(messages[j].first);
                int sum_b = messages[j].second - messages[i].second;
                while (!nums.empty() && sum_a + sum_b > l)
                {
                    sum_a -= nums.top();
                    nums.pop();
                }
                result = std::max(result, int(nums.size()));
            }
        }
        std::cout << result << '\n';
    }

private:
    using ii = std::pair<int, int>;

    int n, l;
    std::vector<ii> messages;
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
