#include <bits/stdc++.h>

class TestCase
{
public:
    void solve()
    {
        std::cin >> n;
        a.resize(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            std::cin >> a[i];
            a[i] -= '0';
        }

        int rightmost_1 = n;
        while (!a[rightmost_1])
        {
            --rightmost_1;
        }

        int rightmost_0 = rightmost_1 - 1;
        while (rightmost_0 > 0 && a[rightmost_0])
        {
            --rightmost_0;
        }

        int leftmost_1 = 1;
        while (!a[leftmost_1])
        {
            ++leftmost_1;
        }

        int result = 0;
        while (rightmost_0 > leftmost_1)
        {
            ++result;
            a[rightmost_0] = 1;
            a[rightmost_1] = 0;
            while (rightmost_0 >= leftmost_1 && a[rightmost_0])
            {
                --rightmost_0;
            }
            while (rightmost_1 >= leftmost_1 && !a[rightmost_1])
            {
                --rightmost_1;
            }
        }
        std::cout << result << '\n';
    }

private:
    template <class T>
    void print(std::vector<T> const &a)
    {
        for (int i = 1; i <= n; ++i)
        {
            std::cerr << int(a[i]) << ' ';
        }
        std::cerr << '\n';
    }

    int n;
    std::vector<uint8_t> a;
};

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
    {
        TestCase test_case;
        test_case.solve();
    }
}
