#include <bits/stdc++.h>

void print(std::vector<int> const &nums)
{
    for (int x : nums)
    {
        std::cerr << x << ' ';
    }
    std::cerr << '\n';
}

class Solution
{
public:
    int firstMissingPositive(std::vector<int> &nums)
    {
        return first_missing_positive(nums);
    }

private:
    int first_missing_positive(std::vector<int> &nums)
    {
        for (int &x : nums)
        {
            while (x > 0 && x <= nums.size() && x != nums[x - 1])
            {
                std::swap(x, nums[x - 1]);
            }
        }
        int i;
        for (i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != i + 1)
            {
                break;
            }
        }
        return i + 1;
    }
};

int main()
{
    std::vector<int> nums = {1, 2, 3};
    Solution solution;
    std::cout << solution.firstMissingPositive(nums) << '\n';
}
