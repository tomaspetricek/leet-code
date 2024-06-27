#include <print>
#include <string>
#include <vector>
#include <string_view>
#include <ctype.h>
#include <cassert>

namespace leet_code
{
    static constexpr char begin_block = '[';
    static constexpr char end_block = ']';

    constexpr int to_integer(const char c)
    {
        return c - '0';
    }

    int parse_integer(const std::string_view &input, std::size_t &index)
    {
        static constexpr int digit_count = 10;
        int num{0};

        for (; input[index] != begin_block; ++index)
        {
            num *= digit_count;
            num += to_integer(input[index]);
        }
        return num;
    }

    std::string decode(const std::string_view &input, std::size_t &index)
    {
        std::string result;
        int times;

        for (; index < input.size(); ++index)
        {
            if (isdigit(input[index]))
            {
                times = parse_integer(input, index);
                const auto token = decode(input, ++index);
                result.reserve(times * token.size());

                for (std::size_t i{0}; i < times; ++i)
                {
                    result += token;
                }
            }
            else if (input[index] == end_block)
            {
                return result;
            }
            else
            {
                result += input[index];
            }
        }
        return result;
    }

    std::string decodeString(std::string s)
    {
        std::size_t index{0};
        return decode(s, index);
    }

    struct sample
    {
        std::string input, result;
    };

    void test_decode_string()
    {
        std::vector<sample> samples{
            sample{{"abcd"}, {"abcd"}},
            sample{{"2[abcd]"}, {"abcdabcd"}},
            sample{{"3[a]2[bc]"}, {"aaabcbc"}},
            sample{{"3[a2[c]]"}, {"accaccacc"}},
            sample{{"2[abc]3[cd]ef"}, {"abcabccdcdcdef"}}};

        for (const auto &s : samples)
        {
            const auto actual_result = decodeString(s.input);
            std::print("actual: {}, expected: {}\n", actual_result, s.result);
            assert(actual_result == s.result);
        }
    }
} // namespace leet_code