//
// Created by Tomáš Petříček on 20.07.2023.
//

#ifndef LEET_CODE_ASTEROID_COLLISION_HPP
#define LEET_CODE_ASTEROID_COLLISION_HPP

#include <cassert>
#include <vector>

namespace leet_code {
    std::vector<int> asteroidCollision(std::vector<int>& asteroids)
    {
        std::vector<int> out;
        for (std::size_t i{0}; i<asteroids.size(); i++) {
            if (asteroids[i]>0) {
                out.push_back(asteroids[i]);
            }
            else {
                while (!out.empty() && out.back()>0 && out.back()<(-asteroids[i])) {
                    out.pop_back();
                }
                if (out.empty() || out.back()<0) {
                    out.push_back(asteroids[i]);
                }
                else if (out.back()==(-asteroids[i])) {
                    out.pop_back();
                }
            }
        }
        return out;
    }

    struct data {
        std::vector<int> before, after;
    };

    void test_asteroid_collision()
    {
        std::vector<data> samples{
                {{5,  10, -5},             {5,  10}},
                {{8,  -8},                 {}},
                {{10, 2,  -5},             {10}},
                {{1,  -2, 4, 5, -7, 8, 1}, {-2, -7, 8, 1}}
        };
        for (auto& s: samples) {
            const auto& after = asteroidCollision(s.before);
            if (after!=s.after) {
                assert(false);
            }
        }
    }
}

#endif //LEET_CODE_ASTEROID_COLLISION_HPP
