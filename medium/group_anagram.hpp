//
// Created by Tomáš Petříček on 25.07.2023.
//

#ifndef LEET_CODE_GROUP_ANAGRAM_HPP
#define LEET_CODE_GROUP_ANAGRAM_HPP

#include <string>
#include <vector>
#include <map>

namespace leet_code {
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
    {
        std::unordered_map<std::string, std::vector<std::string>> groups;
        for (std::size_t i{0}; i<strs.size(); i++) {
            std::string key = strs[i];
            std::sort(key.begin(), key.end());
            groups[key].emplace_back(std::move(strs[i]));
        }
        std::vector<std::vector<std::string>> res;
        res.reserve(groups.size());
        for (const auto& [key, vals]: groups) {
            res.emplace_back(std::move(vals));
        }
        return res;
    }
}

#endif //LEET_CODE_GROUP_ANAGRAM_HPP
