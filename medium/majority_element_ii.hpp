#include <vector>
#include <print>
#include <cassert>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <limits>

namespace leet_code
{
    std::string to_string(std::vector<int> vals)
    {
        constexpr char sep = ',';
        constexpr char start = '{';
        constexpr char end = '}';
        std::string res;
        res += start;

        for (std::size_t i{0}; i < vals.size(); ++i)
        {
            res += std::to_string(vals[i]);

            if (i < vals.size() - 1)
            {
                res += sep;
            }
        }
        res += end;
        return res;
    }

    std::vector<int> majorityElement(std::vector<int> &nums)
    {
        constexpr int max_num = std::numeric_limits<int>::max();
        constexpr std::size_t max_result_size{2};
        const std::size_t min_count{nums.size() / 3};
        int num1{max_num}, num2{max_num};
        int count1{0}, count2{0};

        for (std::size_t i{0}; i < nums.size(); i++)
        {
            if (nums[i] == num1)
            {
                count1++;
            }
            else if (nums[i] == num2)
            {
                count2++;
            }
            else if (count1 == 0)
            {
                num1 = nums[i];
                count1++;
            }
            else if (count2 == 0)
            {
                num2 = nums[i];
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;

        for (std::size_t i{0}; i < nums.size(); ++i)
        {
            if (num1 == nums[i])
            {
                count1++;
            }
            else if (num2 == nums[i])
            {
                count2++;
            }
        }
        std::vector<int> result;
        result.reserve(max_result_size);

        if (count1 > min_count)
        {
            result.emplace_back(num1);
        }
        if (count2 > min_count)
        {
            result.emplace_back(num2);
        }
        return result;
    }

    struct sample
    {
        std::vector<int> nums, result;
    };

    void test_majority_element()
    {
        std::vector<sample> samples{
            sample{{3, 2, 3}, {3}},
            sample{{1}, {1}},
            sample{{1, 2}, {1, 2}}};

        for (auto &s : samples)
        {
            const auto result = majorityElement(s.nums);
            std::print("actual: {}, expected: {}\n", to_string(result), to_string(s.result));
        }
    }
}