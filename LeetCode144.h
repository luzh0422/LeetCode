//
// Created by luzehui on 2024/2/11.
//

#ifndef LEETCODE_LEETCODE144_H
#define LEETCODE_LEETCODE144_H

#include "TreeNode.h"
#include <vector>

using namespace std ;

class LeetCode144 {
public:
    vector<int> preorderTraversal(TreeNode* root);

private:
    void preorderTraversal(TreeNode* root, vector<int>& res);
};


#endif //LEETCODE_LEETCODE144_H
