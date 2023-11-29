//
// Created by 陆泽辉 on 2022/4/29.
//

#include "LeetCode427.h"

QuadTreNode *LeetCode427::construct(vector<vector<int>> &grid) {
    int n = grid.size();
    QuadTreNode* root = new QuadTreNode();
    construct(grid, root, 0, n - 1, 0, n - 1);
    return root;
}

void LeetCode427::construct(vector<vector<int>> &grid, QuadTreNode *node, int rowStart, int rowEnd, int columnStart, int columnEnd) {
    if (rowStart == rowEnd && columnStart == columnEnd) {
        node->isLeaf = true;
        node->val = grid[rowStart][columnStart];
    }
    int curr = grid[rowStart][columnStart];
    bool tag = true;
    for (int i = rowStart; i <= rowEnd; i++) {
        for (int j = columnStart; j <= columnEnd; j++) {
            if (grid[i][j] != curr) {
                tag = false;
                break;
            }
        }
    }
    if (tag) {
        node->isLeaf = true;
        node->val = curr;
    } else {
        node->isLeaf = false;
        node->val = curr;
        int rowMiddle = (rowStart + rowEnd) / 2;
        int columnMiddle = (columnStart + columnEnd) / 2;
        auto topLeft = new QuadTreNode;
        node->topLeft = topLeft;
        auto topRight = new QuadTreNode;
        node->topRight = topRight;
        auto bottomLeft = new QuadTreNode;
        node->bottomLeft = bottomLeft;
        auto bottomRight = new QuadTreNode;
        node->bottomRight = bottomRight;
        construct(grid, topLeft, rowStart, rowMiddle, columnStart, columnMiddle);
        construct(grid, topRight, rowStart, rowMiddle, columnMiddle + 1, columnEnd);
        construct(grid, bottomLeft, rowMiddle + 1, rowEnd, columnStart, columnMiddle);
        construct(grid, bottomRight, rowMiddle + 1, rowEnd, columnMiddle + 1, columnEnd);
    }
}
