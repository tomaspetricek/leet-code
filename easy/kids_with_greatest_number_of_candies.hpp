#include <algorithm>
#include <array>
#include <cassert>
#include <vector>

namespace leet_code
{
    std::vector<bool> kidsWithCandies(std::vector<int> &candies, int extraCandies)
    {
        std::vector<bool> result;
        result.reserve(candies.size());
        int max_count{candies[0]};

        for (const auto &count : candies)
        {
            max_count = std::max(count, max_count);
        }
        for (const auto &count : candies)
        {
            result.emplace_back((count + extraCandies) >= max_count);
        }
        return result;
    }
} // namespace leet_code