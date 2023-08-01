//
// Created by Tomáš Petříček on 31.07.2023.
//

#ifndef LEET_CODE_CAR_FLEET_HPP
#define LEET_CODE_CAR_FLEET_HPP

#include <cassert>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <algorithm>

namespace leet_code {
    struct car {
        int pos;
        float arrival;
    };

    int carFleet(int target, std::vector<int>& positions, std::vector<int>& speeds)
    {
        std::vector<car> cars;
        cars.reserve(speeds.size());
        // computes arrival times == number of steps it would take to reach the target
        for (std::size_t i{0}; i<speeds.size(); i++) {
            cars.emplace_back(car{positions[i], (target-positions[i])/static_cast<float>(speeds[i])});
        }
        // sort by position in descending order
        std::sort(cars.begin(), cars.end(), [](const auto& a, const auto& b) {
            return a.pos>b.pos;
        });
        int fleet_count{0};
        std::size_t i{0};
        float first_arrival;
        // goes from front position to back and counts how many cars catch up
        while (i<cars.size()) {
            fleet_count++;
            first_arrival = cars[i].arrival;
            // add all faster to the fleet
            while (++i<cars.size() && cars[i].arrival<=first_arrival);
        }
        return fleet_count;
    }

    struct sample {
        int target;
        std::vector<int> position, speed;
        int res;
    };

    void test_car_fleet()
    {
        std::vector<sample> samples{
                {12,  {10, 8,  0,  5,  3},                     {2, 4, 1, 1, 3},                3},
                {10,  {3},                                     {3},                            1},
                {100, {0,  2,  4},                             {4, 2, 1},                      1},
                {20,  {6,  2,  17},                            {3, 9, 2},                      2},
                {10,  {8,  3,  7,  4,  6,  5},                 {4, 4, 4, 4, 4, 4},             6},
                {31,  {5,  26, 18, 25, 29, 21, 22, 12, 19, 6}, {7, 6, 6, 4, 3, 4, 9, 7, 6, 4}, 6}
        };
        for (auto& s: samples) {
            auto res = carFleet(s.target, s.position, s.speed);
            assert(res==s.res);
        }
    }
}

#endif //LEET_CODE_CAR_FLEET_HPP
