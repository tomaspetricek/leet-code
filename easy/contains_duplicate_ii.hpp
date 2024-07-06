#include <unordered_map>
#include <vector>

namespace leet_code
{
    bool containsNearbyDuplicate(std::vector<int> &nums, int k)
    {
        std::unordered_map<int, int> occurrences;

        for (std::size_t curr{0}; curr < nums.size(); ++curr)
        {
            auto &prev = occurrences[nums[curr]];

            if (prev && ((curr - (prev - 1)) <= k))
            {
                return true;
            }
            prev = curr + 1;
        }
        return false;
    }
} // namespace leet_code