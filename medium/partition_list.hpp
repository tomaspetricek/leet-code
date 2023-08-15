//
// Created by Tomáš Petříček on 15.08.2023.
//

#ifndef LEET_CODE_PARTITION_LIST_HPP
#define LEET_CODE_PARTITION_LIST_HPP

#include "../list.hpp"
#include <vector>
#include <cassert>

namespace leet_code {
    list::node* partition(list::node* head, int x)
    {
        list::node before_head_lower, before_head_greater;
        list::node* lower{&before_head_lower}, * greater{&before_head_greater};
        while (head) {
            if (head->val<x) {
                lower->next = head;
                lower = lower->next;
            }
            else {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }
        greater->next = nullptr;
        lower->next = before_head_greater.next;
        return before_head_lower.next;
    }

    struct sample {
        list::node* head;
        int x;
        list::node* res;
    };

    void test_partition()
    {
        std::vector<sample> samples{
                {list::create({1, 4, 3, 2, 5, 2}), 3, list::create({1, 2, 2, 4, 3, 5})},
                {list::create({2, 1}),             2, list::create({1, 2})},
        };
        for (auto& s: samples) {
            assert(list::same(s.res, partition(s.head, s.x)));
        }
    }
}

#endif //LEET_CODE_PARTITION_LIST_HPP
