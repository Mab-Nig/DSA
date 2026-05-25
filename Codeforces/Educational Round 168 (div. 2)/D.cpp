#include <bits/stdc++.h>

#define MULTI_TEST_CASE 1

class TestCase
{
public:
    void solve()
    {
        std::cin >> n;
        a.resize(n);
        c.resize(n);
        for (int& x : a)
        {
            std::cin >> x;
        }
        for (int i = 1; i < n; ++i)
        {
            int x;
            std::cin >> x;
            c[x - 1].push_back(i);
        }

        dfs(0);
        std::cout << a[0] << '\n';
    }

private:
    int dfs(int u)
    {
        if (c[u].empty())
        {
            return a[u];
        }

        int min = INT_MAX;
        for (int v : c[u])
        {
            min = std::min(min, dfs(v));
        }
        
        if (u == 0)
        {
            a[u] += min;
            return 0;
        }

        if (a[u] < min)
        {
            a[u] = (a[u] + min) >> 1;
            min = a[u];
        }
        return min;
    }
    
private:
    int n;
    std::vector<int> a;
    std::vector<std::vector<int>> c;
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
