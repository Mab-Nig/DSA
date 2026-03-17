#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    std::string minWindow(std::string const &s, std::string const &t)
    {
        return min_window(s, t);
    }

private:
    std::string min_window(std::string const &s, std::string const &t)
    {
        m = s.size();
        n = t.size();

        window_cnt.resize(char_to_idx('z') + 1, 0);
        t_cnt.resize(char_to_idx('z') + 1, 0);

        for (auto c : t)
        {
            ++t_cnt[char_to_idx(c)];
        }

        {
            std::vector<int> s_cnt(char_to_idx('z') + 1);
            for (auto c : s)
            {
                ++s_cnt[char_to_idx(c)];
            }
            for (int i = 0; i <= char_to_idx('z'); ++i)
            {
                if (s_cnt[i] < t_cnt[i])
                {
                    return "";
                }
            }
        }

        int unsatisfying_cnt = 0;
        for (auto x : t_cnt)
        {
            unsatisfying_cnt += (x > 0);
        }

        int window_l = 0, window_r = s.size() - 1;
        int l = 0, r = 0;
        for (int r = 0; r < s.size(); ++r)
        {
            int s_r_idx = char_to_idx(s[r]);
            ++window_cnt[s_r_idx];
            unsatisfying_cnt -= (window_cnt[s_r_idx] == t_cnt[s_r_idx]);

            if (unsatisfying_cnt > 0)
            {
                continue;
            }

            for (; l <= r && unsatisfying_cnt == 0; ++l)
            {
                int s_l_idx = char_to_idx(s[l]);
                --window_cnt[s_l_idx];
                unsatisfying_cnt += (window_cnt[s_l_idx] == t_cnt[s_l_idx] - 1);
            }

            if (r - l + 1 < window_r - window_l)
            {
                window_l = l - 1;
                window_r = r;
            }
        }

        return s.substr(window_l, window_r - window_l + 1);
    }

    int char_to_idx(char c)
    {
        return c <= 'Z' ? c - 'A' : c - 'a' + 'Z';
    }

    int m, n;
    std::vector<int> t_cnt, window_cnt;

    friend int main(int argc, char **argv);
};

int main(int argc, char **argv)
{
    std::string s = "a", t = "aa";
    Solution solution;
    std::cout << solution.minWindow(s, t) << '\n';
}
