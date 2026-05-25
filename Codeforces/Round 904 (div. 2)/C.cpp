#include <bits/stdc++.h>

#define int ll

using ll = long long;

const int MAXN = 1e5;

struct Segment
{
    int l, r;
};

int t, n, m;
Segment segments[MAXN+1];

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);
    
    std::cin >> t;
    while (t--)
    {
        std::cin >> n >> m;
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> segments[i].l >> segments[i].r;
        }
        
        std::vector<std::tuple<int, int, int>> tips;
        for (int i = 1; i <= n; ++i)
        {
            tips.push_back({segments[i].l, -1, i});
            tips.push_back({segments[i].r, 1, i});
        }
        std::sort(tips.begin(), tips.end());
        
        std::map<int, int> l_cnts, r_cnts;
        l_cnts[1] = 0;
        r_cnts[m] = 0;
        int res = 0, overlap_cnt = 0;
        for (auto const &[pos, type, index] : tips)
        {
            if (type == -1)
            {
                ++overlap_cnt;
                ++l_cnts[pos];
                ++r_cnts[segments[index].r];
            }
            res = std::max(res, overlap_cnt - std::min(l_cnts.begin()->second, r_cnts.rbegin()->second));
            if (type == 1)
            {
                --overlap_cnt;
                --l_cnts[segments[index].l];
                --r_cnts[pos];
            }
        }
        std::cout << res << '\n';
    }
}
