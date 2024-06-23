#include <string>
#include <array>
#include <cassert>
#include <algorithm>

namespace leet_code {
    std::string mergeAlternately(std::string word1, std::string word2) {
        const std::size_t min_size = std::min(word1.size(), word2.size());
        std::string res{};
        res.reserve(word1.size()+word2.size());

        for (std::size_t i{0}; i<min_size; ++i) {
            res += word1[i];
            res += word2[i];
        }
        for (std::size_t i{min_size}; i<word1.size(); ++i) {
            res += word1[i];
        }
        for (std::size_t i{min_size}; i<word2.size(); ++i) {
            res += word2[i];
        }
        return res;
    }

struct sample {
    std::string word1, word2, result;
};

void test_merge_alternaly() {
    constexpr std::size_t sample_count{3};
    const std::array<sample, sample_count> samples{
        sample{{"abc"},{"pqr"},{"apbqcr"}},
        sample{{"ab"},{"pqrs"},{"apbqrs"}},
        sample{{"abcd"},{"pq"},{"apbqcd"}}
    };

    for (const auto& s : samples) {
        const auto actual_res = mergeAlternately(s.word1, s.word2);
        assert(actual_res==s.result);
    }
}   
}