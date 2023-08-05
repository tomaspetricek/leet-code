//
// Created by Tomáš Petříček on 05.08.2023.
//

#ifndef LEET_CODE_FIBONACCI_NUMBER_HPP
#define LEET_CODE_FIBONACCI_NUMBER_HPP

#include <vector>
#include <cassert>
#include <cmath>

namespace leet_code {
    namespace recursion {
        int fib(int n)
        {
            return (n<2) ? n : fib(n-1)+fib(n-2);
        }
    }

    namespace binet {
        double s{sqrt(5)}, phi{(s+1)/2};

        int fib(int n)
        {
            return static_cast<int>(std::round(std::pow(phi, n)/s));
        }
    }


    struct sample {
        int n, res;
    };

    void test_fib()
    {
        std::vector<sample> samples{
                {0, 0},
                {1, 1},
                {2, 1},
                {3, 2},
                {4, 3},
                {5, 5},
        };
        for (auto s: samples) {
            auto res = binet::fib(s.n);
            assert(res==s.res);
        }
    }
}

#endif //LEET_CODE_FIBONACCI_NUMBER_HPP
