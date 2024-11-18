//
// Created by luzehui on 2024/2/22.
//

#include "LeetCode889.h"

TreeNode *LeetCode889::constructFromPrePost(vector<int> &preorder, vector<int> &postorder) {
    int n = preorder.size() - 1;
    return constructFromPrePost(preorder, postorder, 0, n, 0, n);
}

TreeNode *LeetCode889::constructFromPrePost(vector<int> &preorder, vector<int> &postorder, int preorderstart, int preorderend, int postorderstart, int postorderend) {
    if (preorderstart > preorderend) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(preorder[preorderstart]);
    int count = 0;
    for (int i = preorderstart + 1; i < preorderend; i++) {
        if (preorder[i] == postorder[postorderend - 1]) {
            break;
        }
        count++;
    }
    if (count == 0) {
        root->left = constructFromPrePost(preorder, postorder, preorderstart + 1, preorderend, postorderstart, postorderend - 1);
    } else {
        root->left = constructFromPrePost(preorder, postorder, preorderstart + 1, preorderstart + count, postorderstart, postorderstart + count - 1);
        root->right = constructFromPrePost(preorder, postorder, preorderstart + 1 + count, preorderend, postorderstart + count, postorderend - 1);
    }
    return root;
}
