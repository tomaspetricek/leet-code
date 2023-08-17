//
// Created by Tomáš Petříček on 16.08.2023.
//

#ifndef LEET_CODE_BALANCE_A_BINARY_SEARCH_TREE_HPP
#define LEET_CODE_BALANCE_A_BINARY_SEARCH_TREE_HPP

#include "../tree.hpp"
#include <vector>
#include <cassert>

// topic: binary search tree
// link: https://leetcode.com/problems/balance-a-binary-search-tree/
namespace leet_code {
    template<class T>
    class span {
        T* data_;
        std::size_t size_;

    public:
        span(T* data, size_t size)
                :data_(data), size_(size) { }

        const T& operator[](std::size_t i)
        {
            return data_[i];
        }

        bool empty() const
        {
            return !size_;
        }

        T* data() const
        {
            return data_;
        }

        std::size_t size() const
        {
            return size_;
        }
    };

    // inorder traverse
    void traverse(tree::node* node, std::vector<tree::node*>& sorted)
    {
        if (node) {
            traverse(node->left, sorted);
            sorted.emplace_back(node);
            traverse(node->right, sorted);
        }
    }

    tree::node* build(span<tree::node*> nodes)
    {
        if (!nodes.empty()) {
            std::size_t mid{nodes.size()/2};
            auto curr = nodes[mid];
            curr->left = build(span<tree::node*>(nodes.data(), mid));
            curr->right = build(span<tree::node*>(nodes.data()+mid+1, nodes.size()-(mid+1)));
            return curr;
        }
        return nullptr;
    }

    tree::node* balanceBST(tree::node* root)
    {
        std::vector<tree::node*> sorted;
        traverse(root, sorted);
        return build(span<tree::node*>(sorted.data(), sorted.size()));
    }

    struct sample {
        tree::node* root, * res;
    };

    void test_balance_bst()
    {
        std::vector<sample> samples{
//                {
//                        tree::build({1, tree::empty, 2, tree::empty, 3, tree::empty, 4, tree::empty, tree::empty}),
//                        tree::build({2, 1, 3, tree::empty, tree::empty, tree::empty, 4}),
//                },
                {tree::build({2, 1, 3}), tree::build({2, 1, 3})},
        };
        for (auto& s: samples) {
            assert(tree::same(s.res, balanceBST(s.root)));
        }
    }
}

#endif //LEET_CODE_BALANCE_A_BINARY_SEARCH_TREE_HPP
