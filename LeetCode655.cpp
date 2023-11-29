//
// Created by 陆泽辉 on 2022/8/22.
//

#include "LeetCode655.h"
#include <numeric>
#include <queue>

struct Node {
    TreeNode* treeNode;
    int row;
    int column;
};

vector<vector<string>> LeetCode655::printTree(TreeNode *root) {
    int depth = getTreeDepth(root, 0) - 1;
    int m = depth + 1;
    int n = pow(2, depth + 1) - 1;
    vector<vector<string>> ret(m, vector<string>(n, ""));
    queue<Node*> q;
    Node* node = new Node();
    node->treeNode = root;
    node->row = 0;
    node->column = (n - 1) / 2;
    q.push(node);
    ret[0][(n - 1) / 2] = to_string(root->val);
    while (!q.empty()) {
        auto curr = q.front();
        auto currNode = curr->treeNode;
        auto currRow = curr->row;
        auto currColumn = curr->column;
        auto leftNode = currNode->left;
        auto rightNode = currNode->right;
        if (leftNode) {
            auto leftNodeN = new Node();
            leftNodeN->treeNode = leftNode;
            leftNodeN->row = currRow + 1;
            leftNodeN->column = currColumn - pow(2, depth - currRow - 1);
            q.push(leftNodeN);
            ret[leftNodeN->row][leftNodeN->column] = to_string(leftNode->val);
        }
        if (rightNode) {
            auto rightNodeN = new Node();
            rightNodeN->treeNode = rightNode;
            rightNodeN->row = currRow + 1;
            rightNodeN->column = currColumn + pow(2, depth - currRow - 1);
            q.push(rightNodeN);
            ret[rightNodeN->row][rightNodeN->column] = to_string(rightNode->val);
        }
    }
    return ret;
}

int LeetCode655::getTreeDepth(TreeNode *root, int depth) {
    if (!root) {
        return 0;
    }
    return 1 + max(getTreeDepth(root->left, 1), getTreeDepth(root->right, 1));
}
