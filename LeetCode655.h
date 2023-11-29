//
// Created by 陆泽辉 on 2022/8/22.
//

#ifndef LEETCODE_LEETCODE655_H
#define LEETCODE_LEETCODE655_H

#include "TreeNode.h"
#include <string>
#include <vector>

using namespace std;

class LeetCode655 {
public:
    vector<vector<string>> printTree(TreeNode* root);

private:
    int getTreeDepth(TreeNode* root, int depth);
};


#endif //LEETCODE_LEETCODE655_H
