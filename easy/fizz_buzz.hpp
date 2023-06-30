//
// Created by Tomáš Petříček on 26.06.2023.
//

#ifndef LEET_CODE_FIZZ_BUZZ_HPP
#define LEET_CODE_FIZZ_BUZZ_HPP

#include <string>
#include <vector>
#include <iostream>

std::vector<std::string> fizz_buzz(int n)
{
    std::vector<std::string> vals;
    vals.reserve(n);

    for (std::size_t i{1}; i<=n; i++) {
        std::string s;
        if ((i)%3==0) s += "Fizz";
        if ((i)%5==0) s += "Buzz";
        if (s.empty()) s += std::to_string(i);
        vals.emplace_back(std::move(s));
    }
    return vals;
}

void print(const std::vector<std::string>& vals)
{
    for (std::size_t i{0}; i<vals.size(); i++)
        std::cout << vals[i] << ", ";
    std::cout << std::endl;
}

void test_fizz_buzz()
{
    print(fizz_buzz(15));
}

#endif //LEET_CODE_FIZZ_BUZZ_HPP
