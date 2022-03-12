//
// Created by luzh on 2021/4/25.
//

#ifndef LEETCODE_SOLUTION897_H
#define LEETCODE_SOLUTION897_H

#include "TreeNode.h"

#include <vector>

using namespace std;

class Solution897 {
public:
    Solution897() {}
    TreeNode* increasingBST(TreeNode* root);

private:
    void increasingBST(TreeNode* root, vector<int>& ans);
};


#endif //LEETCODE_SOLUTION897_H
