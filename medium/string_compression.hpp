//
// Created by Tomáš Petříček on 17.07.2023.
//

#ifndef LEET_CODE_STRING_COMPRESSION_HPP
#define LEET_CODE_STRING_COMPRESSION_HPP

#include <cassert>
#include <vector>
#include <string>

namespace leet_code {
    int compress(std::vector<char>& chars)
    {
        int count{0};
        int j{1};
        for (std::size_t i{1}; i<chars.size(); i++) {
            if (chars[i-1]==chars[i]) {
                count++;
            }
            else {
                if (count) {
                    for (const auto& digit: std::to_string(count+1)) {
                        chars[j++] = digit;
                    }
                    count = 0;
                }
                chars[j++] = chars[i];
            }
        }
        if (count) {
            for (const auto& digit: std::to_string(count+1)) {
                chars[j++] = digit;
            }
        }
        return j;
    }

    struct data {
        std::vector<char> chars, res;
    };

    void test_compress()
    {
        std::vector<data> samples{
                {{'a', 'a', 'b', 'b', 'c', 'c', 'c'},                               {'a', '2', 'b', '2', 'c', '3'}},
                {{'a'},                                                             {'a'}},
                {{'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'}, {'a', 'b', '1', '2'}},
        };
        for (auto& s: samples) {
            int len = compress(s.chars);
            s.chars.resize(len);
            if (s.chars!=s.res) {
                assert(false);
            }
        }
    }
}

#endif //LEET_CODE_STRING_COMPRESSION_HPP
