#include <bits/stdc++.h>

class TestCase
{
public:
    void solve()
    {
        std::cin >> n >> k;
        a.resize(n + 1);
        x.resize(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> a[i];
        }
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> x[i];
        }

        struct Interval
        {
            int start, duration, idx;
        };

        std::vector<Interval> intervals;
        for (int i = 1; i <= n; ++i)
        {
            int duration = (1LL * a[i] + k - 1) / k;
            int start = std::abs(x[i]) - duration;
            intervals.push_back({start, duration, i});
        }
        std::sort(intervals.begin(), intervals.end(),
                  [](Interval const &a, Interval const &b) -> bool
                  {
                      return a.start < b.start
                             || (a.start == b.start && a.duration < b.duration);
                  });

        int64_t timer = 0;
        int bullet_remaining_cnt = k;
        for (auto const &[start, duration, idx] : intervals)
        {
            if (start < timer)
            {
                std::cout << "NO\n";
                return;
            }

            if (a[idx] < bullet_remaining_cnt)
            {
                bullet_remaining_cnt -= a[idx];
                continue;
            }

            a[idx] -= bullet_remaining_cnt;
            ++timer;
            timer += a[idx] / k;
            bullet_remaining_cnt = k - a[idx] % k;

            if (timer > std::abs(x[idx])
                || (timer == std::abs(x[idx]) && bullet_remaining_cnt < k))
            {
                std::cout << "NO\n";
                return;
            }
        }
        std::cout << "YES\n";
    }

private:
    int n, k;
    std::vector<int> a, x;
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
