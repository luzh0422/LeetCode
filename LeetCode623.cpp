//
// Created by 陆泽辉 on 2022/8/5.
//

#include "LeetCode623.h"

#include <queue>

struct NodeAndParent {
    TreeNode* node_;
    TreeNode* parent_;
    int level_;
    int direction_;

public:
    NodeAndParent(TreeNode* node, TreeNode* parent, int level, int direction) : node_(node), parent_(parent), level_(level), direction_(direction) {}
};

TreeNode *LeetCode623::addOneRow(TreeNode *root, int val, int depth) {
    std::queue<NodeAndParent*> q;
    NodeAndParent* nap = new NodeAndParent(root, nullptr, 1, -1);
    q.push(nap);
    while (!q.empty()) {
        NodeAndParent* nap1 = q.front();
        q.pop();
        int level = nap1->level_;
        auto curr = nap1->node_;
        if (level == depth) {
            auto parent = nap1->parent_;
            int direction = nap1->direction_;
            TreeNode* newNode = new TreeNode(val);
            if (parent == nullptr) {
                newNode->left = curr;
                return newNode;
            } else {
                if (direction == 0) {
                    parent->left = newNode;
                    newNode->left = curr;
                } else if (direction == 1) {
                    parent->right = newNode;
                    newNode->right = curr;
                }
            }
        } else if (level > depth) {
            break;
        }
        if (curr->left) {
            auto nap2 = new NodeAndParent(curr->left, curr, level + 1, 0);
            q.emplace(nap2);
        } else if (level + 1 == depth) {
            curr->left = new TreeNode(val);
        }
        if (curr->right) {
            auto nap2 = new NodeAndParent(curr->right, curr, level + 1, 1);
            q.emplace(nap2);
        } else if (level + 1 == depth) {
            curr->right = new TreeNode(val);
        }
    }
    return root;
}
