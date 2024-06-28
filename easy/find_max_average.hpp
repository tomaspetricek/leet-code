#include <vector>
#include <print>

namespace leet_code
{
    double findMaxAverage(std::vector<int> &nums, int k)
    {
        int sum{0}, max_sum;

        for (std::size_t i{0}; i < k; ++i)
        {
            sum += nums[i];
        }
        max_sum = static_cast<double>(sum);

        for (std::size_t i{static_cast<std::size_t>(k)}; i < nums.size(); ++i)
        {
            sum += nums[i] - nums[i - k];
            max_sum = std::max(max_sum, sum);
        }
        return static_cast<double>(max_sum) / k;
    }

    struct sample
    {
        std::vector<int> nums;
        int k;
        double result;
    };

    void test_find_max_average()
    {
        std::vector<sample> samples{
            sample{{1, 12, -5, -6, 50, 3}, 4, 12.75},
            sample{{5}, 1, 5}};
        for (auto &s : samples)
        {
            std::print("expect: {}, actual: {}\n", s.result, findMaxAverage(s.nums, s.k));
        }
    }
}
