//
// Created by 陆泽辉 on 2022/5/30.
//

#ifndef LEETCODE_LEETCODE1022_H
#define LEETCODE_LEETCODE1022_H

#include "TreeNode.h"

#include <string>

using namespace std;

class LeetCode1022 {
public:
    int sumRootToLeaf(TreeNode* root);

private:
    int sumRootToLeaf(TreeNode* root, string curr);
    int binaryToDecimal(string binary);
};


#endif //LEETCODE_LEETCODE1022_H
