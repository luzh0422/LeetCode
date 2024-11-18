//
// Created by luzehui on 2024/4/2.
//

#include "LeetCode894.h"

/**
 * 分析：
 * 合法的真二叉树FBT有奇数个节点;
 * FBT的左右子树也是FBT;
 * @param n
 * @return
 */
vector<TreeNode *> LeetCode894::allPossibleFBT(int n) {
    if (n == 1) {
        return vector<TreeNode *>(1, new TreeNode(0));
    }
    n--;
    vector<TreeNode *> ret;
    for (int l = 1; l <= n; l += 2) {
        vector<TreeNode*> lrs = allPossibleFBT(l);
        vector<TreeNode*> rrs = allPossibleFBT(n - l);
        for (auto lr : lrs) {
            for (auto rr : rrs) {
                ret.push_back(new TreeNode(0, lr, rr));
            }
        }
    }
    return ret;
}
