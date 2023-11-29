//
// Created by 陆泽辉 on 2022/5/1.
//

#ifndef LEETCODE_LEETCODE1305_H
#define LEETCODE_LEETCODE1305_H

#include "TreeNode.h"

#include <vector>

using namespace std;

class LeetCode1305 {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2);

private:
    void inorder(TreeNode* root, vector<int>& arr);
};


#endif //LEETCODE_LEETCODE1305_H
