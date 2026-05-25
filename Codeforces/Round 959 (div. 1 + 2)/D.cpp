#include <bits/stdc++.h>

#define MULTI_TEST_CASE 1

class Dsu
{
public:
    Dsu(int n)
        : n(n),
          parents(n, -1)
    {
    }

    bool join(int u, int v)
    {
        if ((u = get_parent(u)) == (v = get_parent(v)))
        {
            return 0;
        }

        if (parents[u] > parents[v])
        {
            std::swap(u, v);
        }
        parents[u] += parents[v];
        parents[v] = u;
        return 1;
    }

    int get_parent(int u)
    {
        if (parents[u] < 0)
        {
            return u;
        }

        return parents[u] = get_parent(parents[u]);
    }

private:
    int const n;
    std::vector<int> parents;
};

class TestCase
{
public:
    void solve()
    {
        std::cin >> n;
        a.resize(n);
        for (int& x : a)
        {
            std::cin >> x;
        }

        std::vector<std::pair<int, int>> result;
        std::vector<int> mod_value(n, -1);
        Dsu dsu(n);
        for (int x = n - 1; x >= 1; --x)
        {
            std::fill_n(mod_value.begin(), n, -1);
            for (int i = 0; i < n; ++i)
            {
                int parent_i = dsu.get_parent(i);
                int& mod_value_i = mod_value[a[i] % x];

                if (mod_value_i == -1)
                {
                    mod_value_i = i;
                    continue;
                }

                if (parent_i != dsu.get_parent(mod_value_i))
                {
                    dsu.join(i, mod_value_i);
                    result.emplace_back(i, mod_value_i);
                    break;
                }
            }
        }

        std::cout << "YES\n";
        for (int i = result.size() - 1; i >= 0; --i)
        {
            std::cout << result[i].first + 1 << ' ' << result[i].second + 1
                      << '\n';
        }
    }

private:
    int n;
    std::vector<int> a;
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
