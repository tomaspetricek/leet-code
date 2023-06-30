//
// Created by Tomáš Petříček on 26.06.2023.
//

#ifndef LEETCODE_PATH_SUM_HPP
#define LEETCODE_PATH_SUM_HPP

#include <assert.h>
#include <stack>
#include <queue>
#include <array>

constexpr int e = -1;

struct tree {
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

    template<std::size_t n>
    static node* build(const std::array<int, n>& vals)
    {
        if (!n) return nullptr;

        auto* tree = new node{vals[0]};
        std::queue<node*> parents;
        parents.push(tree);
        std::size_t i{1};

        while (!parents.empty() && i<n) {
            node* parent = parents.front();
            parents.pop();

            if (vals[i]!=e && i<n) {
                parent->left = new node{vals[i]};
                parents.push(parent->left);
            }
            i++;
            if (vals[i]!=e && i<n) {
                parent->right = new node{vals[i]};
                parents.push(parent->right);
            }
            i++;
        }
        return tree;
    }
};

using TreeNode = tree::node;

bool search(TreeNode* node, int target, int sum = 0)
{
    if (node) {
        if (!node->left && !node->right) return node->val+sum==target;
        return search(node->right, target, sum+node->val)
                || search(node->left, target, sum+node->val);
    }
    return false;
}

bool has_path_sum(TreeNode* root, int target)
{
    return search(root, target);
}

void test_path_sum()
{
    std::array vals{5, 4, 8, 11, e, 13, 4, 7, 2, e, e, e, 1};
    auto tree = tree::build(vals);
    int target = 22;
    bool expect{true};
    assert(expect==has_path_sum(tree, target));
}

#endif //LEETCODE_PATH_SUM_HPP
