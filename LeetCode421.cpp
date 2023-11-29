//
// Created by luzehui on 2023/11/4.
//

#include "LeetCode421.h"

void LeetCode421::add(int num) {
    Tire* cur = root;
    for (int k = HIGHBIT; k >= 0; --k) {
        int bit = (num >> k) & 1;
        if (bit == 0) {
            if (!cur->left) {
                cur->left = new Tire();
            }
            cur = cur->left;
        }
        else {
            if (!cur->right) {
                cur->right = new Tire();
            }
            cur = cur->right;
        }
    }
}

int LeetCode421::check(int num) {
    Tire* cur = root;
    int x = 0;
    for (int k = HIGHBIT; k >= 0; --k) {
        int bit = (num >> k) & 1;
        if (bit == 0) {
            // a_i 的第 k 个二进制位为 0，应当往表示 1 的子节点 right 走
            if (cur->right) {
                cur = cur->right;
                x = x * 2 + 1;
            }
            else {
                cur = cur->left;
                x = x * 2;
            }
        }
        else {
            // a_i 的第 k 个二进制位为 1，应当往表示 0 的子节点 left 走
            if (cur->left) {
                cur = cur->left;
                x = x * 2 + 1;
            }
            else {
                cur = cur->right;
                x = x * 2;
            }
        }
    }
    return x;
}

int LeetCode421::findMaximumXOR(vector<int> &nums) {
    int n = nums.size();
    int x = 0;
    for (int i = 1; i < n; ++i) {
        // 将 nums[i-1] 放入字典树，此时 nums[0 .. i-1] 都在字典树中
        add(nums[i - 1]);
        // 将 nums[i] 看作 ai，找出最大的 x 更新答案
        x = max(x, check(nums[i]));
    }
    return x;
}
