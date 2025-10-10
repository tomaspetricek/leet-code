#ifndef LEET_CODE_MAXIMUM_DEPTH_OF_BINARY_TREE_HPP
#define LEET_CODE_MAXIMUM_DEPTH_OF_BINARY_TREE_HPP

#include <array>
#include <queue>
#include <cassert>
#include <print>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

static constexpr int empty = -1;

template <std::size_t Count>
TreeNode *build_tree(const std::array<int, Count> &values)
{
    if constexpr (Count == 0)
    {
        return nullptr;
    }
    else
    {
        auto *tree = new TreeNode{values[0]};
        std::queue<TreeNode *> parents;
        parents.push(tree);
        std::size_t i{1};

        while (!parents.empty() && i < values.size())
        {
            TreeNode *parent = parents.front();
            parents.pop();

            if (values[i] != empty)
            {
                parent->left = new TreeNode{values[i]};
                parents.push(parent->left);
            }
            i++;
            if (values[i] != empty && i < values.size())
            {
                parent->right = new TreeNode{values[i]};
                parents.push(parent->right);
            }
            i++;
        }
        return tree;
    }
}

// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
namespace leet_code
{
    int maxDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    void test_maximum_depth_of_binary_tree()
    {
        const auto tree = build_tree(std::array{3, 9, 20, empty, empty, 15, 7});
        const auto max_depth = maxDepth(tree);
        assert(3 == maxDepth(tree));
    }
}

#endif // LEET_CODE_MAXIMUM_DEPTH_OF_BINARY_TREE_HPP