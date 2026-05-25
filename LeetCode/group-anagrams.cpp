#include <bits/stdc++.h>

class Solution {
public:
  using StringList = std::vector<std::string>;

  std::vector<StringList> groupAnagrams(const StringList &strs) {
    std::vector<StringList> result;
    std::unordered_map<std::string, StringList> str_map;
    for (const auto &s : strs) {
      auto tmp_s = s;
      std::sort(tmp_s.begin(), tmp_s.end());
      str_map[tmp_s].push_back(s);
    }
    for (auto &[key, val] : str_map) {
      result.push_back(std::move(val));
    }
    return result;
  }
};
