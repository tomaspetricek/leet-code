//
// Created by Tomáš Petříček on 17.07.2023.
//

#ifndef LEET_CODE_LIST_HPP
#define LEET_CODE_LIST_HPP

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

    node* reverse(node* head)
    {
        node* curr, * next{nullptr};
        while(head) {
            curr = head;
            head = head->next;
            curr->next = next;
            next = curr;
        }
        return next;
    }
}

#endif //LEET_CODE_LIST_HPP
