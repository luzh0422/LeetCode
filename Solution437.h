//
// Created by luzh on 2021/9/28.
//

#ifndef LEETCODE_SOLUTION437_H
#define LEETCODE_SOLUTION437_H

#include "TreeNode.h"
#include <unordered_map>

using namespace std;

class Solution437 {
public:
    int pathSum(TreeNode* root, int targetSum);

private:
    int pathSum(TreeNode* root, int targetSum, unordered_map<int, int>& um, int currSum);
};


#endif //LEETCODE_SOLUTION437_H
