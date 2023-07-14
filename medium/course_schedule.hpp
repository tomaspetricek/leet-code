//
// Created by Tomáš Petříček on 13.07.2023.
//

#ifndef LEET_CODE_COURSE_SCHEDULE_HPP
#define LEET_CODE_COURSE_SCHEDULE_HPP

#include <vector>
#include <cassert>

// https://leetcode.com/problems/course-schedule/
namespace leet_code {
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites)
    {
        constexpr int c = 0, p = 1;
        bool e{false};
        std::vector<bool> reachable(numCourses, e);
        for (int i{0}; i<prerequisites.size(); i++) {
            reachable[prerequisites[i][c]] = reachable[prerequisites[i][p]] = true;
        }
        int reachable_count = 0;
        for (int i{0}; i<reachable.size(); i++) {
            if (reachable[i]) {
                reachable_count++;
            }
        }
        return (reachable_count==(prerequisites.size()+1));
    }

    struct data {
        int num_courses;
        std::vector<std::vector<int>> prerequisites;
        bool res;
    };

    // not solved yet
    void test_can_finish()
    {
        std::vector<data> samples{
//                {2, {{1, 0}},                         true},
//                {2, {{1, 0}, {0, 1}},                 false},
//                {4, {{1, 2}, {2, 3}, {3, 1}, {0, 1}}, false},
//                {4, {{1, 0}, {2, 1}, {3, 2}},         true},
//                {4, {{1, 0}, {0, 2}, {2, 1}},         false},
//                {4, {{2, 0}, {1, 2}, {0, 1}, {1, 0}}, false},
//                {3, {{1, 2}, {0, 1}, {1, 0}},         false},
//                {5, {{1, 0}, {4, 1}, {4, 3}, {0, 3}}, false},
                {4, {{0, 1}, {3, 1}, {0, 2}},         false},
        };
        for (auto& s: samples) {
            if (s.res!=canFinish(s.num_courses, s.prerequisites)) {
                assert(false);
            }
        }
    }
}

#endif //LEET_CODE_COURSE_SCHEDULE_HPP
