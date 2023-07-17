//
// Created by Tomáš Petříček on 16.07.2023.
//

#ifndef LEET_CODE_REVERSE_LINKED_LIST_HPP
#define LEET_CODE_REVERSE_LINKED_LIST_HPP

#include "../list.hpp"
#include <cassert>
#include <vector>

namespace leet_code {
    using ListNode = list::node;

    ListNode* reverseList(ListNode* head)
    {
        ListNode* curr, * next{nullptr};
        while(head) {
            curr = head;
            head = head->next;
            curr->next = next;
            next = curr;
        }
        return next;
    }

    struct data {
        list::node* in, * out;
    };

    void test_reverse_list()
    {
        std::vector<data> samples{
                {list::create({1, 2, 3, 4, 5}), list::create({5, 4, 3, 2, 1})},
                {list::create({1, 2}),          list::create({2, 1})},
                {list::create({}),              list::create({})},
        };
        for (const auto& s: samples) {
            auto* res = reverseList(s.in);
            if (!list::same(res, s.out)) {
                assert(false);
            }
        }
    }
}

#endif //LEET_CODE_REVERSE_LINKED_LIST_HPP
