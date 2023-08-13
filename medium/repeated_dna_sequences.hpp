//
// Created by Tomáš Petříček on 13.08.2023.
//

#ifndef LEET_CODE_REPEATED_DNA_SEQUENCES_HPP
#define LEET_CODE_REPEATED_DNA_SEQUENCES_HPP

#include <vector>
#include <unordered_map>
#include <string>
#include <string_view>
#include <iostream>

// topic: hash map
// link: https://leetcode.com/problems/repeated-dna-sequences/
namespace leet_code {
    constexpr std::size_t seq_len = 10;

    std::vector<std::string> findRepeatedDnaSequences(std::string s)
    {
        if (s.size()<seq_len) {
            return {};
        }
        std::unordered_map<std::string_view, int> seqs;
        for (std::size_t i{0}; i<(s.size()-seq_len)+1; i++) {
            seqs[std::string_view(s.data()+i, seq_len)]++;
        }
        std::vector<std::string> res;
        for (const auto& [seq, count]: seqs) {
            if (count>1) {
                res.emplace_back(std::string(seq));
            }
        }
        return res;
    }
}

#endif //LEET_CODE_REPEATED_DNA_SEQUENCES_HPP
