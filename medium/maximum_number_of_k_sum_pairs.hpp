#include <vector>
#include <cassert>
#include <print>
#include <algorithm>

namespace leet_code
{
    int maxOperations(std::vector<int> &nums, int k)
    {
        std::sort(nums.begin(), nums.end());
        int count{0}, sum;
        std::size_t low{0}, high{nums.size() - 1};

        while (low < high)
        {
            sum = nums[low] + nums[high];

            if (sum == k)
            {
                count++;
                low++;
                high--;
            }
            else if (sum < k)
            {
                low++;
            }
            else
            {
                high--;
            }
        }
        return count;
    }

    struct sample
    {
        std::vector<int> nums;
        int k, result;
    };

    void test_max_operations()
    {
        std::vector<sample> samples{
            sample{{1, 2, 3, 4}, 5, 2},
            sample{{3, 1, 3, 4, 3}, 6, 1},
        };

        for (auto &s : samples)
        {
            const auto result = maxOperations(s.nums, s.k);
            std::print("actual: {} expected: {}\n", result, s.result);
            assert(result == s.result);
        }
    }
}