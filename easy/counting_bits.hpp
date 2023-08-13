//
// Created by Tomáš Petříček on 13.08.2023.
//

#ifndef LEET_CODE_COUNTING_BITS_HPP
#define LEET_CODE_COUNTING_BITS_HPP

#include <vector>
#include <bit>

// topic: dynamic programming
// link: https://leetcode.com/problems/counting-bits/description/
namespace leet_code {
    std::vector<int> countBits(int n)
    {
        std::vector<int> counts(n+1);
        counts[0] = 0;
        for (std::size_t i{0}; i<=n; i++) {
            // The number that is half the current number has the same bit representation
            // as the first n-1 bits of the current number.
            // If the current number is even, the last bit is 0, 1 otherwise.
            // example: 6(11), 12(110), 13(111)
            counts[i] = counts[i/2]+i%2;
        }
        return counts;
    }
}

#endif //LEET_CODE_COUNTING_BITS_HPP
