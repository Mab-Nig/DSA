#include <bits/stdc++.h>

class TestCase
{
public:
    void solve()
    {
        std::cin >> n >> s;

        std::string rev_s = s;
        std::reverse(rev_s.begin(), rev_s.end());
        std::cout << (s <= rev_s ? s : rev_s + s) << '\n';
    }

private:
    int n;
    std::string s;
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
