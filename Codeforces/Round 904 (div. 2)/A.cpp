#include <bits/stdc++.h>

#define int ll

using ll = long long;

int t, x, k;

int digit_sum(int x)
{
    int sum = 0;
    while (x > 0)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

signed main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    std::cin >> t;
    while (t--)
    {
        std::cin >> x >> k;
        int res = x;
        while (digit_sum(res) % k != 0)
        {
            ++res;
        }
        std::cout << res << '\n';
    }
}
