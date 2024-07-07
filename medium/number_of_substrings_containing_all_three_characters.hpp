#include <string>
#include <vector>
#include <print>
#include <cassert>

namespace leet_code
{
    int numberOfSubstrings(std::string s)
    {
        constexpr std::size_t char_count = 3;
        constexpr char first = 'a';
        std::array<int, char_count> counts{{0}};
        std::size_t f{0}, l{0};
        int result{0};

        for (; l < s.size(); ++l)
        {
            counts[s[l] - first]++;

            while (counts[0] && counts[1] && counts[2])
            {
                counts[s[f++] - first]--;
            }
            result += f;
        }
        return result;
    }

    struct sample
    {
        std::string s;
        int result;
    };

    void test_number_of_substring()
    {
        std::vector<sample> samples{
            sample{{"abcabc"}, 10},
            sample{{"aaacb"}, 3},
            sample{{"abc"}, 1},
            sample{{"abb"}, 0}};

        for (auto &s : samples)
        {
            const auto result = numberOfSubstrings(s.s);
            std::print("actual: {} expected: {}\n", result, s.result);
            assert(result == s.result);
        }
    }
}