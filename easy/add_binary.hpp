//
// Created by Tomáš Petříček on 14.07.2023.
//

#ifndef LEET_CODE_ADD_BINARY_HPP
#define LEET_CODE_ADD_BINARY_HPP

#include <iostream>
#include <cassert>
#include <string>
#include <string_view>
#include <algorithm>

// https://leetcode.com/problems/add-binary/
namespace leet_code {
    std::string addBinary(std::string a, std::string b) {
        std::string ans;
        int carry{0};
        std::size_t i{a.size()}, j{b.size()};
        ans.reserve(std::max(i, j)+1);

        while (i!=0 || j!=0 || carry) {
            if (i!=0) {
                carry += a[--i]-'0';
            }
            if (j!=0) {
                carry += b[--j]-'0';
            }
            ans.push_back(carry%2+'0');
            carry /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    struct data {
        std::string a, b, sum;
    };

    // works
    void test_add_binary()
    {
        std::vector<data> samples{
                {{"11"},   {"1"},    {"100"}},
                {{"10"},   {"1"},    {"11"}},
                {{"1010"}, {"1011"}, {"10101"}},
        };
        for (const auto& s: samples) {
            const auto& res = addBinary(s.a, s.b);
            if (s.sum!=res) {
                std::cout << s.sum << ',' << res << std::endl;
                assert(false);
            }
        }
    }
}

#endif //LEET_CODE_ADD_BINARY_HPP
