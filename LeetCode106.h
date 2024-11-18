//
// Created by luzehui on 2024/2/21.
//

#ifndef LEETCODE_LEETCODE106_H
#define LEETCODE_LEETCODE106_H

#include <vector>
#include "TreeNode.h"

using namespace std;

class LeetCode106 {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);

private:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int inorderstart, int inorderend, int postorderstart, int postorderend);
};


#endif //LEETCODE_LEETCODE106_H
