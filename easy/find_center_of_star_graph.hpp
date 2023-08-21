//
// Created by Tomáš Petříček on 21.08.2023.
//

#ifndef LEET_CODE_FIND_CENTER_OF_STAR_GRAPH_HPP
#define LEET_CODE_FIND_CENTER_OF_STAR_GRAPH_HPP

#include <vector>

namespace leet_code {
    int findCenter(std::vector<std::vector<int>>& edges)
    {
        return (edges[0][0]==edges[1][0] || edges[0][0]==edges[1][1]) ? edges[0][0] : edges[0][1];
    }
}

#endif //LEET_CODE_FIND_CENTER_OF_STAR_GRAPH_HPP
