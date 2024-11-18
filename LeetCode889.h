//
// Created by luzehui on 2024/2/22.
//

#ifndef LEETCODE_LEETCODE889_H
#define LEETCODE_LEETCODE889_H

#include <vector>
#include "TreeNode.h"

using namespace std;

class LeetCode889 {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder);

private:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder, int preorderstart, int preorderend, int postorderstart, int postorderend);
};


#endif //LEETCODE_LEETCODE889_H
