//
// Created by 陆泽辉 on 2022/8/27.
//

#include "LeetCode662.h"

#include <vector>

using namespace std;

int LeetCode662::widthOfBinaryTree(TreeNode *root) {
    unsigned long long res = 1;
    vector<pair<TreeNode*, unsigned long long>> q;
    q.emplace_back(root, 1L);
    /**
     * 典型的广度优先遍历；
     */
    while (!q.empty()) {
        vector<pair<TreeNode*, unsigned long long>> tmp;
        for (auto &[node, index] : q) {
            if (node->left) {
                tmp.emplace_back(node->left, index * 2);
            }
            if (node->right) {
                tmp.emplace_back(node->right, index * 2 + 1);
            }
        }
        /**
         * 利用数组，而不用队列，可以快速求得收尾的宽度；
         */
        res = max(res, q.back().second - q.front().second + 1);
        /**
         * 做一个右值赋值；
         */
        q = move(tmp);
    }
    return res;
}
