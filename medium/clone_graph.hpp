//
// Created by Tomáš Petříček on 10.08.2023.
//

#ifndef LEET_CODE_CLONE_GRAPH_HPP
#define LEET_CODE_CLONE_GRAPH_HPP

#include <vector>
#include <cassert>
#include <unordered_map>

namespace leet_code {
// Definition for a Node.
    class Node {
    public:
        int val;
        std::vector<Node*> neighbors;

        Node()
        {
            val = 0;
            neighbors = std::vector<Node*>();
        }
        Node(int _val)
        {
            val = _val;
            neighbors = std::vector<Node*>();
        }
        Node(int _val, std::vector<Node*> _neighbors)
        {
            val = _val;
            neighbors = _neighbors;
        }
    };

    Node* clone(Node* node, std::unordered_map<Node*, Node*>& copies) {
        auto it = copies.find(node);
        if (it==copies.end()) {
            it = copies.insert({node, new Node(node->val)}).first;
            // clone neighbors
            for (Node* next : node->neighbors) {
                it->second->neighbors.emplace_back(clone(next, copies));
            }
        }
        return it->second;
    }

    Node* cloneGraph(Node* node)
    {
        if (!node) {
            return nullptr;
        }
        std::unordered_map<Node*, Node*> copies;
        return clone(node, copies);
    }

    void test_clone_graph()
    {
        {
            std::vector<Node*> nodes;
            nodes.emplace_back(new Node{1});
            nodes.emplace_back(new Node{2});
            nodes.emplace_back(new Node{3});
            nodes.emplace_back(new Node{4});
            nodes[0]->neighbors.emplace_back(nodes[1]);
            nodes[0]->neighbors.emplace_back(nodes[3]);
            nodes[1]->neighbors.emplace_back(nodes[0]);
            nodes[1]->neighbors.emplace_back(nodes[2]);
            nodes[2]->neighbors.emplace_back(nodes[1]);
            nodes[2]->neighbors.emplace_back(nodes[3]);
            nodes[3]->neighbors.emplace_back(nodes[0]);
            nodes[3]->neighbors.emplace_back(nodes[2]);
            cloneGraph(nodes[0]);
        }
        {
            std::vector<Node*> nodes;
            nodes.emplace_back(new Node{1});
            cloneGraph(nodes[0]);
        }
        {
            std::vector<Node*> nodes;
            nodes.emplace_back(new Node{1});
            nodes.emplace_back(new Node{2});
            nodes.emplace_back(new Node{3});
            nodes.emplace_back(new Node{4});
            nodes.emplace_back(new Node{5});
            nodes.emplace_back(new Node{6});
            nodes.emplace_back(new Node{7});
            nodes.emplace_back(new Node{8});
            nodes[0]->neighbors.emplace_back(nodes[1]);
            nodes[0]->neighbors.emplace_back(nodes[2]);
            nodes[0]->neighbors.emplace_back(nodes[3]);
            nodes[1]->neighbors.emplace_back(nodes[0]);
            nodes[1]->neighbors.emplace_back(nodes[6]);
            nodes[2]->neighbors.emplace_back(nodes[0]);
            nodes[3]->neighbors.emplace_back(nodes[0]);
            nodes[3]->neighbors.emplace_back(nodes[4]);
            nodes[3]->neighbors.emplace_back(nodes[5]);
            nodes[3]->neighbors.emplace_back(nodes[7]);
            nodes[4]->neighbors.emplace_back(nodes[3]);
            nodes[5]->neighbors.emplace_back(nodes[3]);
            nodes[6]->neighbors.emplace_back(nodes[1]);
            nodes[7]->neighbors.emplace_back(nodes[3]);
            cloneGraph(nodes[0]);
        }
    }
}

#endif //LEET_CODE_CLONE_GRAPH_HPP
