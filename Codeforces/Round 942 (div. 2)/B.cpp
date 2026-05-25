#include <bits/stdc++.h>

#define MULTI_TEST_CASE 1

class TestCase
{
public:
    void solve()
    {
        std::cin >> n >> s;

        int u_cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            u_cnt += (s[i] == 'U');
        }

        bool is_alice = 1;
        while (u_cnt > 0)
        {
            int i = 0;
            if (u_cnt & 1)
            {
                for (; i < n && (s[i] == 'D' || is_adj_same(i)); ++i)
                {
                }
            }
            else
            {
                for (; i < n && (s[i] == 'D' || !is_adj_same(i)); ++i)
                {
                }
            }
            flip_adj(i);
            s.erase(i, 1);
            --n;
            --u_cnt;
            is_alice = !is_alice;
        }
        std::cout << (!is_alice ? "YES\n" : "NO\n");
    }

private:
    bool is_adj_same(int idx)
    {
        if (n == 1)
        {
            return 1;
        }

        if (idx == 0)
        {
            return s[idx + 1] == s.back();
        }

        if (idx == n - 1)
        {
            return s[idx - 1] == s[0];
        }

        return s[idx + 1] == s[idx - 1];
    }

    void flip_adj(int idx)
    {
        if (n <= 2)
        {
            return;
        }

        if (idx == 0)
        {
            flip(s[idx + 1]);
            flip(s.back());
            return;
        }

        if (idx == n - 1)
        {
            flip(s[0]);
            flip(s[idx - 1]);
        }
    }

    void flip(char &c)
    {
        if (c == 'U')
        {
            c = 'D';
        }
        else if (c == 'D')
        {
            c = 'U';
        }
    }

private:
    int n;
    std::string s;
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
