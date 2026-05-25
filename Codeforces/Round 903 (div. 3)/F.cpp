#include <bits/stdc++.h>

class TestCase
{
public:
    void solve()
    {
        std::cin >> n >> k;
        is_marked.resize(n + 1, 0);
        adjs.resize(n + 1);
        for (int i = 0; i < k; ++i)
        {
            int x;
            std::cin >> x;
            is_marked[x] = 1;
        }
        for (int i = 1; i < n; ++i)
        {
            int u, v;
            std::cin >> u >> v;
            adjs[u].push_back(v);
            adjs[v].push_back(u);
        }

        int u = find_deepest(1, 0).first;
        int diameter = find_deepest(u, 0).second;
        std::cout << (diameter + 1) / 2 << '\n';
    }

private:
    using ii = std::pair<int, int>;

    ii find_deepest(int u, int par)
    {
        ii result = {-1, -1};
        if (is_marked[u])
        {
            result = std::make_pair(u, 0);
        }
        for (int v : adjs[u])
        {
            if (v == par)
            {
                continue;
            }

            ii child_result = find_deepest(v, u);
            if (child_result.first != -1
                && (result.first == -1
                    || result.second < child_result.second + 1))
            {
                result = child_result;
                ++result.second;
            }
        }
        return result;
    }

    int n, k;
    std::vector<uint8_t> is_marked;
    std::vector<std::vector<int>> adjs;
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
