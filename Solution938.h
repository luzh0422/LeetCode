//
// Created by luzh on 2021/4/27.
//

#ifndef LEETCODE_SOLUTION938_H
#define LEETCODE_SOLUTION938_H

#include "TreeNode.h";

class Solution938 {
public:
    Solution938() {}
    int rangeSumBST(TreeNode* root, int low, int high);

private:
    void rangeSumBST(TreeNode* root, int low, int high, int& sum);
};


#endif //LEETCODE_SOLUTION938_H
