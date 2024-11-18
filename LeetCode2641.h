//
// Created by luzehui on 2024/2/7.
//

#ifndef LEETCODE_LEETCODE2641_H
#define LEETCODE_LEETCODE2641_H

#include "TreeNode.h"
#include <vector>

using namespace std;

class LeetCode2641 {
public:
    TreeNode* replaceValueInTree(TreeNode* root);
private:
    void bfs1(TreeNode* root, vector<int>& sums);
    void bfs2(TreeNode* root, vector<int>& sums);
};


#endif //LEETCODE_LEETCODE2641_H
