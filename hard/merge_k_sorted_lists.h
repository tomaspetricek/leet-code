//
// Created by Tomáš Petříček on 03.06.2022.
//

#ifndef LEETCODE_MERGE_K_SORTED_LISTS_H
#define LEETCODE_MERGE_K_SORTED_LISTS_H

#include <vector>
#include <queue>

struct ListNode {
    int val;
    ListNode* next;
    ListNode()
            :val(0), next(nullptr) { }
    ListNode(int x)
            :val(x), next(nullptr) { }
    ListNode(int x, ListNode* next)
            :val(x), next(next) { }
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists)
    {
        std::priority_queue<std::pair<int, ListNode*>, std::vector<std::pair<int, ListNode*>>,
                std::greater<>> nodes;

        for (const auto& list : lists) {
            if (list==nullptr) continue;

            nodes.push(std::make_pair(list->val, list));
        }

        ListNode fst;
        ListNode* head = &fst;
        ListNode* prev = head;
        ListNode *smallest, *rest;

        while (!nodes.empty()) {
            smallest = nodes.top().second;
            nodes.pop();

            prev->next = smallest;
            rest = smallest->next;
            prev = smallest;

            if (rest != nullptr && !nodes.empty())
                nodes.push(std::make_pair(rest->val, rest));
        }

        return head->next;
    }
};

void test_merge_k_lists(){
    std::vector<ListNode*> lists {
            new ListNode(1, new ListNode(4, new ListNode(5, nullptr))),
            new ListNode(1, new ListNode(3, new ListNode(4, nullptr))),
            new ListNode(2, new ListNode(6, nullptr))
    };

    auto sol = Solution();
    ListNode* sorted = sol.mergeKLists(lists);
}

#endif //LEETCODE_MERGE_K_SORTED_LISTS_H
