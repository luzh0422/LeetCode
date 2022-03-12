//
// Created by luzh on 2021/5/16.
//

#include "Solution421.h"

int Solution421::findMaximumXOR(vector<int> &nums) {
    int size = nums.size();
    int x = 0;
    for (int i = 1; i < size; i++) {
        add(nums[i - 1]);
        x = max(x, check(nums[i]));
    }
    return x;
}

/**
 * 构建字典树tire
 * @param num
 */
void Solution421::add(int num) {
    Trie* cur = root;
    for (int k = HIGH_BIT; k >= 0; k--) {
        int bit = (num >> k) & 1;
        if (bit == 0) {
            if (!cur->left) {
                cur->left = new Trie();
            }
            cur = cur->left;
        } else {
            if (!cur->right) {
                cur->right = new Trie();
            }
            cur = cur->right;
        }
    }
}

int Solution421::check(int num) {
    Trie* cur = root;
    int x = 0;
    for (int k = HIGH_BIT; k >= 0; k--) {
        int bit = (num >> k) & 1;
        if (bit == 0) {
            /**
             * 查找元素的第k个二进制位位0，应当往表示1的子节点right走
             */
            if (cur->right) {
                cur = cur->right;
                x = x * 2 + 1;
            } else {
                cur = cur->left;
                x = x * 2;
            }
        } else {
            if (cur->left) {
                cur = cur->left;
                x = x * 2 + 1;
            } else {
                cur = cur->right;
                x = x * 2;
            }
        }
    }
    return x;
}
