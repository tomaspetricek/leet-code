//
// Created by Tomáš Petříček on 12.07.2023.
//

#ifndef LEET_CODE_FIND_EVENTUAL_STATE_HPP
#define LEET_CODE_FIND_EVENTUAL_STATE_HPP

#include <vector>
#include <cassert>

// https://leetcode.com/problems/find-eventual-safe-states/
namespace leet_code {
    namespace too_slow {
        void find_loop(int prev, std::vector<std::vector<int>>& graph, std::vector<bool>& transient,
                std::vector<bool>& visited, bool& found)
        {
            visited[prev] = true;
            const auto& neighbors = graph[prev];
            for (std::size_t i{0}; i<neighbors.size() && !found; i++) {
                int next = neighbors[i];
                if (visited[next] || transient[next]) {
                    found = true;
                    transient[next] = true;
                }
                else {
                    find_loop(next, graph, transient, visited, found);
                }
            }
            if (found) {
                transient[prev] = true;
            }
            visited[prev] = false;
        }

        std::vector<int> eventualSafeNodes(std::vector<std::vector<int>>& graph)
        {
            std::vector<bool> transient(graph.size(), false), visited(graph.size(), false);
            bool found{false};
            std::size_t safe_count{transient.size()};
            for (int from{0}; from<graph.size(); from++) {
                if (!transient[from]) {
                    find_loop(from, graph, transient, visited, found);
                    if (found) {
                        safe_count--;
                    }
                    found = false;
                }
                else {
                    safe_count--;
                }
            }
            std::vector<int> safe;
            safe.reserve(safe_count);
            for (int i{0}; i<transient.size(); i++) {
                if (!transient[i]) {
                    safe.emplace_back(i);
                }
            }
            return safe;
        }
    }

    std::vector<int> eventualSafeNodes(std::vector<std::vector<int>>& graph)
    {

    }

    struct data {
        std::vector<std::vector<int>> graph;
        std::vector<int> safe_nodes;
    };

    void test_eventual_safe_nodes()
    {
        std::vector<data> samples{
                {{{1, 2},       {2, 3}, {5},    {0},    {5}, {}, {}}, {2, 4, 5, 6}},
                {{{1, 2, 3, 4}, {1, 2}, {3, 4}, {0, 4}, {}},          {4}},
                {{{1},          {2},    {1}},                         {}},
        };
        for (auto& s: samples) {
            assert(s.safe_nodes==too_slow::eventualSafeNodes(s.graph));
        }
    }
}

#endif //LEET_CODE_FIND_EVENTUAL_STATE_HPP
