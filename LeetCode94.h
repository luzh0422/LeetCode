//
// Created by luzehui on 2024/2/10.
//

#ifndef LEETCODE_LEETCODE94_H
#define LEETCODE_LEETCODE94_H

#include "TreeNode.h"
#include <vector>

using namespace std;

class LeetCode94 {
public:
    vector<int> inorderTraversal(TreeNode* root);
private:
    void inorderTraversal(TreeNode* root, vector<int>& res);
};


#endif //LEETCODE_LEETCODE94_H
