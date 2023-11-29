//
// Created by luzehui on 2023/11/25.
//

#ifndef LEETCODE_LEETCODE1457_H
#define LEETCODE_LEETCODE1457_H

#include "TreeNode.h"
#include <vector>

using namespace std;

class LeetCode1457 {
public:
    int pseudoPalindromicPaths (TreeNode* root);

private:
    int dfs(TreeNode* root, vector<int> record);
};


#endif //LEETCODE_LEETCODE1457_H
