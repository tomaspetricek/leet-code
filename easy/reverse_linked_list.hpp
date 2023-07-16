//
// Created by Tomáš Petříček on 16.07.2023.
//

#ifndef LEET_CODE_REVERSE_LINKED_LIST_HPP
#define LEET_CODE_REVERSE_LINKED_LIST_HPP

#include <cassert>
#include <vector>

namespace leet_code {
    namespace list {
        struct node {
            int val;
            node* next;
            node()
                    :val(0), next(nullptr) { }
            node(int x)
                    :val(x), next(nullptr) { }
            node(int x, node* next)
                    :val(x), next(next) { }
        };

        node* create(const std::vector<int>& nums)
        {
            node ahead;
            node* curr{&ahead};
            for (auto num: nums) {
                curr->next = new node(num);
                curr = curr->next;
            }
            return ahead.next;
        }

        bool same(node* fst, node* snd)
        {
            while (fst && snd) {
                if (fst->val!=snd->val) {
                    return false;
                }
                fst = fst->next;
                snd = snd->next;
            }
            return !fst && !snd;
        }
    }

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
