#include <bits/stdc++.h>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string_view s)
    {
        int res = 0;
        std::unordered_map<char, int> char_cnt;

        int i = 0, j = 0;
        for (; j < s.size(); ++j)
        {
            auto char_iter = char_cnt.emplace(s[j], 0).first;
            ++char_iter->second;

            if (char_iter->second <= 1)
            {
                continue;
            }

            res = std::max(res, j - i);
            for (; i <= j; ++i)
            {
                --char_cnt[s[i]];

                if (char_iter->second == 1)
                {
                    ++i;
                    break;
                }
            }
        }
        res = std::max(res, j - i);
        return res;
    }
};

int main()
{
    Solution solution;
    std::cout << solution.lengthOfLongestSubstring("abcabcbb") << '\n';
}
