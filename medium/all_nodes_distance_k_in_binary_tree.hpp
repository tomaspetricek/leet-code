//
// Created by Tomáš Petříček on 11.07.2023.
//

#ifndef LEET_CODE_ALL_NODES_DISTANCE_K_IN_BINARY_TREE_HPP
#define LEET_CODE_ALL_NODES_DISTANCE_K_IN_BINARY_TREE_HPP

#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
#include "../tree.hpp"

// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
namespace leet_code {

    using TreeNode = tree::node;
    int e = tree::empty;

    void search(TreeNode* root, int target, int k, std::vector<int>& res)
    {
        std::stack<TreeNode*> nodes;
        nodes.push(root);
        bool found{false};

        while (!nodes.empty() && !found) {
            auto curr = nodes.top();
            nodes.pop();
            if (curr) {
                if (curr->val==target) {
                    found = true;
                }
                else {
                    nodes.push(curr->right);
                    nodes.push(curr->left);
                }
            }
        }
    }

    std::vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
        std::vector<int> res;
        int dist = 0;
        search(root, target->val, k, res);
        return res;
    }

    struct data {
        tree::node* root;
        tree::node* target;
        int k;
        std::vector<int> res{7, 4, 1};
    };

    void test_distance_k()
    {
        std::vector<data> samples{
                {tree::build({3, 5, 1, 6, 2, 0, 8, e, e, 7, 4}), new tree::node{5}, 2, {7, 4, 1}},
//                {tree::build({3, 5, 1, 6, 2, 0, 8, e, e, 7, 4}), new tree::node{3}, 1, {5, 1}},
//                {tree::build({3, 5, 1, 6, 2, 0, 8, e, e, 7, 4}), new tree::node{6}, 1, {5}},
        };
        for (const auto& sample: samples) {
            assert(sample.res==distanceK(sample.root, sample.target, sample.k));
        }
    }
}

#endif //LEET_CODE_ALL_NODES_DISTANCE_K_IN_BINARY_TREE_HPP
