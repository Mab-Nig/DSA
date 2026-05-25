#include <bits/stdc++.h>

#define int ll

using ll = long long;

const int MAXN = 1e5;

int t, n, right_nearest_0s[MAXN+1], connect_indexes[MAXN+1];
bool a[MAXN+1];

signed main()
{
	std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> t;
    while (t--)
    {
        std::cin >> n;
        for (int i = 0; i < n; ++i)
        {
            char c;
            std::cin >> c;
            a[i] = c-'0';
        }
        std::reverse(a, a+n);

        int one_cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            one_cnt += a[i];
        }
        
        right_nearest_0s[n] = n;
        for (int i = n-1; i >= 0; --i)
        {
            right_nearest_0s[i] = (!a[i] ? i : right_nearest_0s[i+1]);
        }

        int res = 0;
        std::queue<std::pair<int, int>> pairs;
        for (int i = 0; i <= n; ++i)
        {
            if (i == n)
            {
                std::cout << (one_cnt == 0 ? 0 : -1);
                continue;
            }

            if (i > 0)
            {
                std::cout << (n-i < one_cnt ? -1 : res) << ' ';
            }
            
            if (a[i])
            {
                int curr_rightmost_0 = (pairs.empty() ? i : pairs.back().second);
                int rightmost_0 = right_nearest_0s[curr_rightmost_0 + 1];
                pairs.push({i, rightmost_0});
                res += rightmost_0 - i;
                continue;
            }

            if (pairs.empty())
            {
                continue;
            }

            int one_id = pairs.front().first;
            int rightmost_0 = right_nearest_0s[pairs.back().second + 1];
            pairs.pop();
            res -= i - one_id;
            pairs.push({one_id, rightmost_0});
            res += rightmost_0 - one_id;
        }
        std::cout << '\n';
    }
}
