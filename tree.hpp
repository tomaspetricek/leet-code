//
// Created by Tomáš Petříček on 11.07.2023.
//

#ifndef LEET_CODE_TREE_HPP
#define LEET_CODE_TREE_HPP

#include <vector>
#include <queue>

namespace tree {
    struct node {
        int val;
        node* left;
        node* right;
        node()
                :val(0), left(nullptr), right(nullptr) { }
        explicit node(int x)
                :val(x), left(nullptr), right(nullptr) { }
        node(int x, node* left, node* right)
                :val(x), left(left), right(right) { }
    };

    static constexpr int empty = -1;

    static node* build(const std::vector<int>& vals)
    {
        if (vals.empty()) return nullptr;

        auto* tree = new node{vals[0]};
        std::queue<node*> parents;
        parents.push(tree);
        std::size_t i{1};

        while (!parents.empty() && i<vals.size()) {
            node* parent = parents.front();
            parents.pop();

            if (vals[i]!=empty && i<vals.size()) {
                parent->left = new node{vals[i]};
                parents.push(parent->left);
            }
            i++;
            if (vals[i]!=empty && i<vals.size()) {
                parent->right = new node{vals[i]};
                parents.push(parent->right);
            }
            i++;
        }
        return tree;
    }
}

#endif //LEET_CODE_TREE_HPP
