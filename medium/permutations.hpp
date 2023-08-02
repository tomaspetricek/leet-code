//
// Created by Tomáš Petříček on 02.08.2023.
//

#ifndef LEET_CODE_PERMUTATIONS_HPP
#define LEET_CODE_PERMUTATIONS_HPP

#include <vector>
#include <cmath>

namespace leet_code {
    constexpr std::size_t max{10}, not_used{max+1};

    void
    generate(std::vector<std::vector<int>>& perms, std::vector<int>& nums, std::vector<int>& seq, std::size_t depth = 0)
    {
        if (depth==seq.size()) {
            perms.emplace_back(seq);
        }
        else {
            for (std::size_t i{0}; i<seq.size(); i++) {
                if (seq[i]==not_used) {
                    seq[i] = nums[depth];
                    generate(perms, nums, seq, depth+1);
                    seq[i] = not_used;
                }
            }
        }
    }

    // time complexity: O(n*n!)
    // space complexity: O(n!)
    std::vector<std::vector<int>> permute(std::vector<int>& nums)
    {
        std::size_t count{static_cast<size_t>(std::tgamma(nums.size()+1))}; // nums.size()! (factorial)
        std::vector<std::vector<int>> perms;
        perms.reserve(count);
        std::vector<int> seq(nums.size(), not_used);
        generate(perms, nums, seq);
        return perms;
    }

    void test_permute()
    {
        std::vector<int> nums{{1, 2, 3}};
        auto res = permute(nums);
    }
}

#endif //LEET_CODE_PERMUTATIONS_HPP
