#include <bits/stdc++.h>

class Solution
{
public:
    int longestValidParentheses(std::string const &s)
    {
        return longest_valid_parentheses(s);
    }

private:
    int longest_valid_parentheses(std::string const &s)
    {
        int len = s.size();

        if (len == 0)
        {
            return 0;
        }

        std::vector<int> sum(len);
        std::vector<int> sum_min_idx(2 * len + 1, INT_MAX);
        std::vector<int> sum_max_idx(2 * len + 1, -1);

        for (int i = 0; i < len; ++i)
        {
            sum[i] = (i == 0 ? 0 : sum[i - 1]) + char_weight(s[i]);
        }

        for (int i = 0; i < len; ++i)
        {
            sum_max_idx[len + sum[i]] = i;
        }

        int result = 0;
        for (int i = len - 1; i >= 0; --i)
        {
            sum_min_idx[len + sum[i]] = i;

            int sum_prev = (i == 0 ? len : len + sum[i - 1]);
            if (sum_min_idx[sum_prev - 1] < len)
            {
                maximize(result, sum_min_idx[sum_prev - 1] - i);
            }
            else if (sum_max_idx[sum_prev] != -1)
            {
                maximize(result, sum_max_idx[sum_prev] - i + 1);
            }
        }
        return result;
    }

    int char_weight(char c)
    {
        return c == '(' ? 1 : -1;
    }

    template <class T>
    void minimize(T &a, T const &b)
    {
        a = std::min(a, b);
    }

    template <class T>
    void maximize(T &a, T const &b)
    {
        a = std::max(a, b);
    }
};

int main()
{
    std::string s;
    Solution solution;
    std::cout << solution.longestValidParentheses(s) << '\n';
}
