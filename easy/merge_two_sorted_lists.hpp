#ifndef LEET_CODE_REMOVE_DUPLICATES_FROM_SORTED_LIST_HPP
#define LEET_CODE_REMOVE_DUPLICATES_FROM_SORTED_LIST_HPP

#include <cassert>
#include <array>
#include <cstdint>
#include <print>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

template <std::size_t Count>
ListNode *build_list(const std::array<int, Count> &values)
{
    ListNode before_head;
    ListNode *prev{&before_head};

    for (const auto &val : values)
    {
        const auto curr = new ListNode(val);
        prev->next = curr;
        prev = curr;
    }
    return before_head.next;
}

bool are_same(const ListNode *rhs, const ListNode *lhs)
{
    if (!rhs && !lhs)
    {
        return true;
    }
    if (!rhs || !lhs)
    {
        return false;
    }
    if (rhs->val != lhs->val)
    {
        return false;
    }
    return are_same(rhs->next, lhs->next);
}

void print(const ListNode *head)
{
    if (head)
    {
        std::print("{}, ", head->val);
        print(head->next);
        return;
    }
    std::println("\n");
}

namespace leet_code
{
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1)
        {
            return list2;
        }
        if (!list2)
        {
            return list1;
        }
        if (list1->val < list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }

    void test_merge_two_sorted_lists()
    {
        assert(are_same(mergeTwoLists(build_list(std::array{1, 2, 4}), build_list(std::array{1, 3, 4})), build_list(std::array{1, 1, 2, 3, 4, 4})));
    }
}

#endif // LEET_CODE_REMOVE_DUPLICATES_FROM_SORTED_LIST_HPP