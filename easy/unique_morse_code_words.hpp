#include <array>
#include <print>
#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>

namespace leet_code
{
    std::string morse_code_encode(const std::string &token)
    {
        constexpr std::size_t letter_count = 26;
        static const std::array<std::string_view, letter_count> morse_letters{
            {{".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."}, {"--."}, {"...."}, {".."}, {".---"}, {"-.-"}, {".-.."}, {"--"}, {"-."}, {"---"}, {".--."}, {"--.-"}, {".-."}, {"..."}, {"-"}, {"..-"}, {"...-"}, {".--"}, {"-..-"}, {"-.--"}, {"--.."}}};
        std::string encoded;

        for (const auto &letter : token)
        {
            std::size_t index = letter - 'a';
            encoded += morse_letters[index];
        }
        return encoded;
    }

    int uniqueMorseRepresentations(std::vector<std::string> &words)
    {
        std::unordered_set<std::string> unique;

        for (const auto &word : words)
        {
            unique.insert(morse_code_encode(word));
        }
        return static_cast<int>(unique.size());
    }

    struct sample
    {
        std::vector<std::string> words;
        int result;
    };

    void test_unique_morse_representations()
    {
        std::vector<sample> samples{sample{{{"gin"}, {"zen"}, {"gig"}, {"msg"}}, 2},
                                    sample{{"a"}, 1}};
        for (auto &s : samples)
        {
            std::print("actual: {}, expect: {}\n", uniqueMorseRepresentations(s.words),
                       s.result);
        }
    }
} // namespace leet_code