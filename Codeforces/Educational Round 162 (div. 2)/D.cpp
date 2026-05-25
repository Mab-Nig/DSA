#include <bits/stdc++.h>

class TestCase
{
public:
    void solve()
    {
        std::cin >> n;
        a.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> a[i];
        }

        std::vector<int64_t> pre(n + 1, 0), suf(n + 2, 0);
        for (int i = 1; i <= n; ++i)
        {
            pre[i] = pre[i - 1] + a[i];
            suf[i] = suf[i + 1] + a[i];
        }

        std::vector<int> cons_pre(n + 1, 1);
        std::vector<int> cons_suf(n + 2, 1);
        for (int i = 1; i <= n; ++i)
        {
            cons_pre[i] = (a[i] == a[i - 1]) + 1;
        }
        for (int i = n; i > 0; --i)
        {
            cons_suf[i] = (a[i] == a[i + 1]) + 1;
        }

        int result = -1;
        for (int i = 1; i <= n; ++i)
        {
            int res_pre = -1, res_suf = -1;
            [&]() -> void
            {
                if (i == n)
                {
                    return;
                }

                int start =
                    (cons_suf[i + 1] == 1 ? i + 1 : i + 1 + cons_suf[i + 1]);

                auto it = std::upper_bound(pre.begin() + start, pre.end(),
                                           pre[i] + a[i]);
                if (it != pre.end())
                {
                    res_suf = it - pre.begin() - i;
                }
            }();

            if (i > 1)
            {
                int end =
                    (cons_pre[i - 1] == 1 ? i - 2 : i - 2 - cons_pre[i - 1]);
                auto it = std::lower_bound(pre.begin(), pre.begin() + end,
                                           pre[i - 1] - a[i]);
                if (it != pre.begin())
                {
                    res_pre = i - (it - pre.begin());
                }
            }

            int tresult;
            if (res_pre == -1)
            {
                tresult = res_pre;
            }
            else if (res_suf == -1)
            {
                tresult = res_suf;
            }
            else
            {
                tresult = std::min(res_pre, res_suf);
            }

            if (tresult != -1)
            {
                if (result == -1 || result > tresult)
                {
                    result = tresult;
                }
            }
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
