#include <vector>
#include <cassert>
#include <print>
#include <algorithm>

namespace leet_code
{
    int majorityElement(std::vector<int> &nums)
    {
        std::size_t count{0};
        int candidate{0};

        // moore voting algorithm
        for (const auto &num : nums)
        {
            if (count == 0)
            {
                candidate = num;
            }
            if (candidate == num)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return candidate;
    }

    struct sample
    {
        std::vector<int> nums;
        int result;
    };

    void test_majority_element()
    {
        std::vector<sample> samples{
            sample{{1}, 1},
            sample{{2, 2}, 2},
            sample{{2, 1, 1}, 1},
            sample{{3, 2, 3}, 3},
            sample{{2, 2, 1, 1, 1, 2, 2}, 2}};

        for (auto &s : samples)
        {
            const auto result = majorityElement(s.nums);
            std::print("actual: {} expected: {}\n", result, s.result);
            assert(result == s.result);
        }
    }
}