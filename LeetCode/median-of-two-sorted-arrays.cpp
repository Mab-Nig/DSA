#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

class Solution
{
public:
    double findMedianSortedArrays(std::vector<int> &nums1,
                                  std::vector<int> &nums2)
    {
        return find_median_sorted_arrays(nums1, nums2);
    }

private:
    double find_median_sorted_arrays(std::vector<int> const &nums_1,
                                     std::vector<int> const &nums_2)
    {
        if (nums_1.empty())
        {
            if (nums_2.empty())
            {
                return 0;
            }

            return find_median_sorted_arrays(nums_2, nums_1);
        }

        int low_median_idx = (nums_1.size() + nums_2.size() + 1) / 2;
        double low_median =
            find_element_at_ranking(low_median_idx, nums_1, nums_2);

        if ((nums_1.size() + nums_2.size()) & 1)
        {
            return low_median;
        }

        double high_median =
            find_element_at_ranking(low_median_idx + 1, nums_1, nums_2);
        return 1.0 * (low_median + high_median) / 2;
    }

    double find_element_at_ranking(int ranking, std::vector<int> const &nums_1,
                                   std::vector<int> const &nums_2,
                                   bool is_nums_swapped = 0)
    {
        int result_idx = -1;
        int l = 0, r = nums_1.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (is_valid(mid, ranking, nums_1, nums_2))
            {
                result_idx = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        double result = (result_idx == -1 ? std::nan("1") : nums_1[result_idx]);
        if (!is_nums_swapped)
        {
            double result_swapped =
                find_element_at_ranking(ranking, nums_2, nums_1, 1);
            if (std::isnan(result))
            {
                result = result_swapped;
            }
            else
            {
                if (!std::isnan(result_swapped) && result > result_swapped)
                {
                    result = result_swapped;
                }
            }
        }
        return result;
    }

    bool is_valid(int idx, int ranking, std::vector<int> const &nums_1,
                  std::vector<int> const &nums_2)
    {
        int leq_cnt =
            idx + 1
            + std::distance(
                nums_2.begin(),
                std::upper_bound(nums_2.begin(), nums_2.end(), nums_1[idx]));
        return leq_cnt >= ranking;
    }

    friend int main();
};

int main()
{
    std::vector<int> nums_1 = {1, 2};
    std::vector<int> nums_2 = {3, 4};
    Solution solution;
    for (int i = 1; i <= nums_1.size() + nums_2.size(); ++i)
    {
        std::cout << solution.find_element_at_ranking(i, nums_1, nums_2)
                  << '\n';
    }
    std::cout << solution.findMedianSortedArrays(nums_1, nums_2) << '\n';
}
