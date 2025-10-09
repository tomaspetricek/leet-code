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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head && head->next)
        {
            if (head->val == head->next->val)
            {
                head->next = head->next->next;
                deleteDuplicates(head);
            }
            else
            {
                deleteDuplicates(head->next);
            }
        }
        return head;
    }

    void test_remove_duplicates_from_sorted_list()
    {
        const auto values = build_list(std::array{1, 1, 1});
        assert(are_same(values, values));
        assert(!are_same(nullptr, values));
        assert(are_same(deleteDuplicates(build_list(std::array{1, 1, 1})), build_list(std::array{1})));
        assert(are_same(deleteDuplicates(build_list(std::array{1, 1, 2})), build_list(std::array{1, 2})));
        assert(are_same(deleteDuplicates(build_list(std::array{1, 1, 2, 3, 3})), build_list(std::array{1, 2, 3})));
    }
}

#endif // LEET_CODE_REMOVE_DUPLICATES_FROM_SORTED_LIST_HPP