#include <vector>
#include <print>
#include <cassert>
#include <algorithm>

namespace leet_code
{
    int hIndex(std::vector<int> &citations)
    {
        std::sort(citations.begin(), citations.end(), std::greater<>{});

        for (std::size_t i{0}; i < citations.size(); ++i)
        {
            if (citations[i] < (i + 1))
            {
                return i;
            }
        }
        return static_cast<int>(citations.size());
    }

    struct sample
    {
        std::vector<int> citations;
        int result;
    };

    void test_h_index()
    {
        std::vector<sample> samples{
            sample{{3, 0, 6, 1, 5}, 3},
            sample{{1, 3, 1}, 1},
            sample{{2, 3, 1}, 2},
            sample{{3, 3, 1}, 2},
            sample{{3, 3, 4}, 3},
        };

        for (auto &s : samples)
        {
            const auto result = hIndex(s.citations);
            std::print("actual: {}, expected: {}\n", result, s.result);
            assert(result == s.result);
        }
    }
}