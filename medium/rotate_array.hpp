#include <cassert>
#include <print>
#include <string>
#include <vector>

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

    void reverse(std::vector<int> &nums, std::size_t first, std::size_t last)
    {
        while (first < last)
        {
            std::swap(nums[first], nums[last]);
            first++;
            last--;
        }
    }

    void rotate(std::vector<int> &nums, int k)
    {
        k %= nums.size();

        if (k == 0)
        {
            return;
        }
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }

    struct sample
    {
        std::vector<int> nums;
        int k;
        std::vector<int> result;
    };

    void test_rotate()
    {
        std::vector<sample> samples{
            sample{{1, 2, 3, 4, 5, 6, 7}, 3, {5, 6, 7, 1, 2, 3, 4}},
            sample{{-1, -100, 3, 99}, 2, {3, 99, -1, -100}},
            sample{{1, 2, 3, 4, 5, 6, 7}, 7, {1, 2, 3, 4, 5, 6, 7}},
            sample{{1, 2, 3, 4, 5, 6, 7}, 8, {7, 1, 2, 3, 4, 5, 6}},
            sample{{1}, 0, {1}},
        };

        for (auto &s : samples)
        {
            rotate(s.nums, s.k);
            std::print("actual: {}, expected: {}\n", to_string(s.nums),
                       to_string(s.result));
            assert(s.nums == s.result);
        }
    }
} // namespace leet_code