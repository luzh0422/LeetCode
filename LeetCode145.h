//
// Created by luzehui on 2024/2/12.
//

#ifndef LEETCODE_LEETCODE145_H
#define LEETCODE_LEETCODE145_H

#include "TreeNode.h"
#include <vector>

using namespace std;

class LeetCode145 {
public:
    vector<int> postorderTraversal(TreeNode* root);

private:
    void postorderTraversal(TreeNode* root, vector<int>& res);
};


#endif //LEETCODE_LEETCODE145_H
