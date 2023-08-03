//
// Created by Tomáš Petříček on 03.08.2023.
//

#ifndef LEET_CODE_SUBRECTANGLE_QUERIES_HPP
#define LEET_CODE_SUBRECTANGLE_QUERIES_HPP

#include <vector>
#include <functional>
#include <cassert>
#include <iostream>

namespace leet_code {
    int null{std::numeric_limits<int>::quiet_NaN()};

    class SubrectangleQueries {
        std::vector<std::vector<int>> rect;

    public:
        SubrectangleQueries() = default;

        SubrectangleQueries(std::vector<std::vector<int>>& rectangle)
                :rect{std::move(rectangle)} { }

        void updateSubrectangle(int row1, int col1, int row2, int col2, int val)
        {
            for (int r{row1}; r<=row2; r++) {
                for (int c{col1}; c<=col2; c++) {
                    rect[r][c] = val;
                }
            }
        }

        int getValue(int row, int col)
        {
            return rect[row][col];
        }
    };

    namespace task {
        struct init {
            std::vector<std::vector<int>> rectangle;

            explicit init(const std::vector<std::vector<int>>& rectangle)
                    :rectangle(rectangle) { }

            int operator()(SubrectangleQueries& queries)
            {
                queries = SubrectangleQueries(rectangle);
                return null;
            }
        };

        struct update_subrectangle {
            int row1, col1, row2, col2, new_val;

            explicit update_subrectangle(int row1, int col1, int row2, int col2, int new_val)
                    :row1{row1}, col1{col1}, row2{row2}, col2{col2}, new_val{new_val} { }

            int operator()(SubrectangleQueries& queries) const
            {
                queries.updateSubrectangle(row1, col1, row2, col2, new_val);
                return null;
            }
        };

        struct get_value {
            int row, col;

            explicit get_value(int row, int col)
                    :row{row}, col{col} { }

            int operator()(SubrectangleQueries& queries) const
            {
                return queries.getValue(row, col);
            }
        };
    }

    using task_t = std::function<int(SubrectangleQueries&)>;

    struct data {
        std::vector<std::pair<task_t, int>> tasks;
    };

    void test_subrectangle_queries()
    {
        std::vector<data> samples{
                {
                        {
                                {task::init{{{1, 2, 1}, {4, 3, 4}, {3, 2, 1}, {1, 1, 1}}}, null},
                                {task::get_value{0, 2}, 1},
                                {task::update_subrectangle{0, 0, 3, 2, 5}, null},
                                {task::get_value{0, 2}, 5},
                                {task::get_value{3, 1}, 5},
                                {task::update_subrectangle{3, 0, 3, 2, 10}, null},
                                {task::get_value{3, 1}, 10},
                                {task::get_value{0, 2}, 5},
                        }
                },
        };
        SubrectangleQueries queries;
        for (const auto& s: samples) {
            for (std::size_t i{0}; i<s.tasks.size(); i++) {
                auto& t = s.tasks[i];
                if (t.second!=t.first(queries)) {
                    std::cout << "i: " << i << std::endl;
                    assert(false);
                }
            }
        }
    }
}

#endif //LEET_CODE_SUBRECTANGLE_QUERIES_HPP
