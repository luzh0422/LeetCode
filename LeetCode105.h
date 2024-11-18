//
// Created by luzehui on 2024/2/20.
//

#ifndef LEETCODE_LEETCODE105_H
#define LEETCODE_LEETCODE105_H

#include <vector>
#include "TreeNode.h"

using namespace std;

class LeetCode105 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);

private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int preorderstart, int preorderend, int inorderstart, int inorderend);
};


#endif //LEETCODE_LEETCODE105_H
