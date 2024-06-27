#include <algorithm>
#include <array>
#include <cassert>
#include <print>
#include <vector>

namespace leet_code
{
    int longestOnes(std::vector<int> &nums, int can_flip_count)
    {
        int first{0}, last{0}, result{0}, zero_count{0}, num_count{static_cast<int>(nums.size())};

        // sliding window
        while (last < num_count)
        {
            if (nums[last++] == 0)
            {
                zero_count++;
            }
            while (zero_count > can_flip_count)
            {
                if (nums[first++] == 0)
                {
                    zero_count--;
                }
            }
            result = std::max(result, last - first);
        }
        return result;
    }

    struct sample
    {
        std::vector<int> nums;
        int can_flip_count, result;
    };

    void test_longest_ones()
    {
        constexpr std::size_t sample_count{3};
        std::vector<sample> samples{
            sample{{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0}, 2, 6},
            sample{{0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1}, 3, 10},
            sample{{0, 0, 0, 1}, 4, 4}};

        for (auto &s : samples)
        {
            const auto actual_result = longestOnes(s.nums, s.can_flip_count);
            std::print("actual: {}, expect: {}\n", actual_result, s.result);
        }
    }
} // namespace leet_code