//
// Created by Tomáš Petříček on 17.07.2023.
//

#ifndef LEET_CODE_ADD_TWO_NUMBERS_2_HPP
#define LEET_CODE_ADD_TWO_NUMBERS_2_HPP

#include "../list.hpp"
#include <cassert>
#include <vector>

namespace leet_code {
    // https://leetcode.com/problems/add-two-numbers-ii/
    list::node* addTwoNumbers(list::node* l1, list::node* l2)
    {
        l1 = list::reverse(l1);
        l2 = list::reverse(l2);
        list::node* curr, * prev;
        curr = prev = nullptr;
        int carry{0}, sum, val1, val2;
        while (l1 || l2 || carry) {
            val1 = val2 = 0;
            if (l1) {
                val1 = l1->val;
                l1 = l1->next;
            }
            if (l2) {
                val2 = l2->val;
                l2 = l2->next;
            }
            sum = val1+val2+carry;
            carry = sum/10;
            curr = new list::node(sum%10);
            curr->next = prev;
            prev = curr;
        }
        return curr;
    }

    struct data {
        list::node* l1, * l2, * sum;
    };

    void test_add_two_numbers()
    {
        std::vector<data> samples{
                {list::create({7, 2, 4, 3}), list::create({5, 6, 4}), list::create({7, 8, 0, 7})},
                {list::create({2, 4, 3}),    list::create({5, 6, 4}), list::create({8, 0, 7})},
                {list::create({}),           list::create({}),        list::create({})},
                {list::create({5}),          list::create({5}),       list::create({1, 0})},
        };
        for (const auto& s: samples) {
            auto* sum = addTwoNumbers(s.l1, s.l2);
            if (!list::same(sum, s.sum)) {
                assert(false);
            }
        }
    }
}

#endif //LEET_CODE_ADD_TWO_NUMBERS_2_HPP
