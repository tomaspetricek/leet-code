#include <vector>
#include <cassert>
#include <string>
#include <map>
#include <print>
#include <unordered_map>
#include <algorithm>


namespace leet_code {
    int minimum_pushes(std::string word) {
        constexpr std::size_t letter_count{26};
        constexpr char first_letter{'a'};
        std::array<std::size_t, letter_count> counts{};
        
        for (const auto& letter : word) {
            counts[letter - first_letter]++;
        }
        std::sort(counts.begin(), counts.end(), std::greater<>{});
        constexpr std::size_t pads_count{8};
        std::size_t key_count{0};
        int result{0};

        for (const auto& count : counts) {
            if (count == 0) {
                break;
            }
            result += count * ((key_count++ / pads_count) + 1);
        }
        return result;
    }

    struct sample {
        std::string word;
        int result;
    };

    void test_minimum_pushes() {
        std::vector<sample> samples{
            sample{{"abcde"}, 5},
            sample{{"xyzxyzxyzxyz"}, 12},
            sample{{"aabbccddeeffgghhiiiiii"}, 24},
            sample{{"abzaqsqcyrbzsrvamylmyxdjl"}, 32}
        };

        for (const auto& s : samples) {
            const auto result = minimum_pushes(s.word);
            std::print("expect: {}, actual: {}\n", s.result, result);
            assert(result==s.result);
        }
    }
}