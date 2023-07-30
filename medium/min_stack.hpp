//
// Created by Tomáš Petříček on 30.07.2023.
//

#ifndef LEET_CODE_MIN_STACK_HPP
#define LEET_CODE_MIN_STACK_HPP

#include <cassert>
#include <limits>
#include <stack>
#include <iostream>
#include <stack>
#include <algorithm>

int null{std::numeric_limits<int>::quiet_NaN()};

// https://leetcode.com/problems/min-stack/
namespace leet_code {
    class MinStack {
        struct data {
            int val, min;
        };
        std::stack<data> vals_;

    public:
        void push(int val)
        {
            if (vals_.empty()) {
                vals_.push({val, val});
            }
            else {
                vals_.push({val, std::min(val, vals_.top().min)});
            }
        }

        void pop()
        {
            vals_.pop();
        }

        int top()
        {
            return vals_.top().val;
        }

        int getMin()
        {
            return vals_.top().min;
        }
    };

    namespace task {
        struct init {
            int operator()(MinStack& stack) const
            {
                stack = MinStack();
                return null;
            }
        };

        struct push {
            int val;

            explicit push(int val)
                    :val{val} { }

            int operator()(MinStack& stack) const
            {
                stack.push(val);
                return null;
            }
        };

        struct pop {
            int operator()(MinStack& stack) const
            {
                stack.pop();
                return null;
            }
        };

        struct get_min {
            int operator()(MinStack& stack) const
            {
                return stack.getMin();
            }
        };

        struct top {
            int operator()(MinStack& stack) const
            {
                return stack.top();
            }
        };
    }

    using task_t = std::function<int(MinStack&)>;

    struct sample {
        std::vector<std::pair<task_t, int>> tasks;
    };

    void test_min_stack()
    {
        std::vector<sample> samples{
                {
                        {
                                {task::init{}, null},
                                {task::push{-2}, null}, {task::push{0}, null}, {task::push{-3}, null},
                                {task::get_min{}, -3}, {task::pop{}, null}, {task::top{}, 0}, {task::get_min{}, -2}
                        }
                }
        };
        MinStack stack;
        for (const auto& s: samples) {
            for (std::size_t i{0}; i<s.tasks.size(); i++) {
                auto& t = s.tasks[i];
                if (t.second!=t.first(stack)) {
                    std::cout << "i: " << i << std::endl;
                    assert(false);
                }
            }
        }
    }
}
#endif //LEET_CODE_MIN_STACK_HPP
