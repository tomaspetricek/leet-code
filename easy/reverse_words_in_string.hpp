
#include <array>
#include <cassert>
#include <string>

#include <print>

namespace leet_code
{
    std::string reverseWords(std::string s)
    {
        constexpr char space{' '};
        std::string res;
        res.reserve(s.size());
        std::int32_t l{static_cast<std::int32_t>(s.size()) - 1}, f{l};

        do
        {
            // skip spaces
            while (l >= 0 && s[l] == space)
            {
                l--;
            }
            f = l;
            // pass word
            while (f >= 0 && s[f] != space)
            {
                f--;
            }
            // copy word
            if (l > f)
            {
                for (std::int32_t i{f + 1}; i <= l; ++i)
                {
                    res += s[i];
                }
                res += space;
            }
            l = f;
        } while (f > 0);

        res.pop_back();
        return res;
    }

    struct sample
    {
        std::string input, result;
    };

    void test_reverse_words()
    {
        constexpr std::size_t sample_count{6};
        std::array<sample, sample_count> samples{
            sample{{"s"}, {"s"}},
            sample{{"s kaq      "}, {"kaq s"}},
            sample{{"    l    abc s kaq      "}, {"kaq s abc l"}},
            sample{{"the sky is blue"}, {"blue is sky the"}},
            sample{{"  hello world  "}, {"world hello"}},
            sample{{"a good   example"}, {"example good a"}},
        };
        for (const auto &s : samples)
        {
            assert(reverseWords(s.input) == s.result);
        }
    }
} // namespace leet_code