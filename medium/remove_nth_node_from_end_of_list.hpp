//
// Created by Tomáš Petříček on 19.07.2023.
//

#ifndef LEET_CODE_REMOVE_NTH_NODE_FROM_END_OF_LIST_HPP
#define LEET_CODE_REMOVE_NTH_NODE_FROM_END_OF_LIST_HPP

#include "../list.hpp"
#include <cassert>
#include <vector>

namespace leet_code {
    list::node* removeNthFromEnd(list::node* head, int n)
    {
        if (!head->next) {
            return nullptr;
        }
        list::node* after{head}, * before{head};
        while (n--) {
            after = after->next;
        }
        if (!after) {
            return head->next;
        }
        while (after->next) {
            after = after->next;
            before = before->next;
        }
        before->next = before->next->next;
        return head;
    }

    struct data {
        list::node* head;
        int n;
        list::node* res;
    };

    void test_remove_nth_from_end()
    {
        std::vector<data> samples{
                {list::create({1, 2, 3, 4, 5}), 2, list::create({1, 2, 3, 5})},
                {list::create({1, 2, 3, 4, 5}), 1, list::create({1, 2, 3, 4})},
                {list::create({1}),             1, list::create({})},
                {list::create({1, 2}),          1, list::create({1})},
        };
        for (auto& s: samples) {
            auto* res = removeNthFromEnd(s.head, s.n);
            if (!list::same(res, s.res)) {
                assert(false);
            }
        }
    }
}

#endif //LEET_CODE_REMOVE_NTH_NODE_FROM_END_OF_LIST_HPP
