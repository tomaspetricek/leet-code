//
// Created by Tomáš Petříček on 17.07.2023.
//

#ifndef LEET_CODE_EXCEL_SHEET_COLUMN_TITLE_HPP
#define LEET_CODE_EXCEL_SHEET_COLUMN_TITLE_HPP

#include <cassert>
#include <string>

// https://leetcode.com/problems/excel-sheet-column-number/
namespace leet_code {
    namespace alphabet {
        constexpr char first = 'A';
        constexpr char size = 26;
    }

    std::string convertToTitle(int columnNumber)
    {
        std::string title;
        int num;
        while (columnNumber>alphabet::size) {
            num = columnNumber%(alphabet::size+1);
            title.push_back(alphabet::first+num);
            columnNumber /= alphabet::size+1;
        }
        title.push_back(alphabet::first+columnNumber-1);
        std::cout << title << std::endl;
        std::reverse(title.begin(), title.end());
        return title;
    }

    struct data {
        int columnNumber;
        std::string title;
    };

    // not working
    void test_convert_to_title()
    {
        std::vector<data> samples{
//                {1,     "A"},
//                {28,    "AB"},
//                {701,   "ZY"},
                {16900, "XYZ"},
        };
        for (const auto& s: samples) {
            const auto& title = convertToTitle(s.columnNumber);
            if (title!=s.title) {
                assert(false);
            }
        }
    }
}

#endif //LEET_CODE_EXCEL_SHEET_COLUMN_TITLE_HPP
