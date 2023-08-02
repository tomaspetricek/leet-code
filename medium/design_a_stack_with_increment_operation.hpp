//
// Created by Tomáš Petříček on 02.08.2023.
//

#ifndef LEET_CODE_DESIGN_A_STACK_WITH_INCREMENT_OPERATION_HPP
#define LEET_CODE_DESIGN_A_STACK_WITH_INCREMENT_OPERATION_HPP

#include <vector>
#include <cassert>
#include <functional>
#include <limits>
#include <iostream>

int null{std::numeric_limits<int>::quiet_NaN()};

// https://leetcode.com/problems/design-a-stack-with-increment-operation/
namespace leet_code {
    class CustomStack {
        static constexpr int empty = -1;
        std::vector<int> data;

    public:
        CustomStack() = default;

        CustomStack(int maxSize)
        {
            data.reserve(maxSize);
        }

        void push(int x)
        {
            if (data.size()!=data.capacity()) {
                data.emplace_back(x);
            }
        }

        int pop()
        {
            if (data.empty()) {
                return empty;
            }
            else {
                int val = data.back();
                data.pop_back();
                return val;
            }
        }

        void increment(int k, int val)
        {
            for (std::size_t i{0}; i<std::min(static_cast<std::size_t>(k), data.capacity()); i++) {
                data[i] += val;
            }
        }
    };

    namespace task {
        struct init {
            int max_size;

            explicit init(int max_size)
                    :max_size{max_size} { }

            int operator()(CustomStack& stack) const
            {
                stack = CustomStack(max_size);
                return null;
            }
        };

        struct push {
            int val;

            explicit push(int val)
                    :val{val} { }

            int operator()(CustomStack& stack) const
            {
                stack.push(val);
                return null;
            }
        };

        struct pop {
            int operator()(CustomStack& stack) const
            {
                return stack.pop();
            }
        };

        struct increment {
            int k, val;

            explicit increment(int k, int val)
                    :k{k}, val{val} { }

            int operator()(CustomStack& stack) const
            {
                stack.increment(k, val);
                return null;
            }
        };
    }

    using task_t = std::function<int(CustomStack&)>;

    struct sample {
        std::vector<std::pair<task_t, int>> tasks;
    };

    void test_custom_stack()
    {
        std::vector<sample> samples{
                {
                        {
                                {task::init{3}, null},
                                {task::push{1}, null}, {task::push{2}, null},
                                {task::pop{}, 2},
                                {task::push{2}, null}, {task::push{3}, null}, {task::push{4}, null},
                                {task::increment{5, 100}, null}, {task::increment{2, 100}, null},
                                {task::pop{}, 103}, {task::pop{}, 202}, {task::pop{}, 201}, {task::pop{}, -1},
                        }
                }
        };
        CustomStack stack;
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

#endif //LEET_CODE_DESIGN_A_STACK_WITH_INCREMENT_OPERATION_HPP
