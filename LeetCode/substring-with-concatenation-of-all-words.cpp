#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution
{
public:
    std::vector<int> findSubstring(std::string const &s,
                                   std::vector<std::string> const &words)
    {
        return find_substring(s, words);
    }

private:
    std::vector<int> find_substring(std::string const &s,
                                    std::vector<std::string> const &words)
    {
        word_size = words.front().size();
        for (auto const &word : words)
        {
            ++words_cnt[word];
        }

        substr_size = word_size * words.size();
        std::vector<int> result;
        for (int offset = 0; offset < word_size; ++offset)
        {
            std::unordered_map<std::string, int> substr_cnt;
            int greater_cnt = 0;

            // first substr
            for (int i = offset; i < offset + substr_size; i += word_size)
            {
                std::string curr_word = s.substr(i, word_size);
                if (substr_cnt[curr_word]++ == words_cnt[curr_word])
                {
                    ++greater_cnt;
                }
            }
            if (greater_cnt == 0)
            {
                result.push_back(offset);
            }

            for (int left = offset + word_size;
                 left + substr_size - 1 < s.size(); left += word_size)
            {
                int right = left + substr_size - 1;
                std::string popped_string =
                    s.substr(left - word_size, word_size);
                std::string pushed_string =
                    s.substr(right - word_size + 1, word_size);
                if (--substr_cnt[popped_string] == words_cnt[popped_string])
                {
                    --greater_cnt;
                }
                if (substr_cnt[pushed_string]++ == words_cnt[pushed_string])
                {
                    ++greater_cnt;
                }
                if (greater_cnt == 0)
                {
                    result.push_back(left);
                }
            }
        }
        return result;
    }

    int word_size, substr_size;
    std::unordered_map<std::string, int> words_cnt;
};

int main(int argc, char **argv)
{
    std::string s = "barfoofoobarthefoobarman";
    std::vector<std::string> words = {"bar", "foo", "the"};

    Solution solution;
    std::vector<int> result = solution.findSubstring(s, words);
    for (int x : result)
    {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}
