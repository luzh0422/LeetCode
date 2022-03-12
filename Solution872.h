//
// Created by luzh on 2021/5/10.
//

#ifndef LEETCODE_SOLUTION872_H
#define LEETCODE_SOLUTION872_H

#include "TreeNode.h"
#include <vector>

using namespace std;

class Solution872 {
public:
    Solution872() {}
    bool leafSimilar(TreeNode* root1, TreeNode* root2);

private:
    void dfs(TreeNode* root, vector<int>& arr);
};


#endif //LEETCODE_SOLUTION872_H
