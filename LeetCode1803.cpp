//
// Created by 陆泽辉 on 2023/1/5.
//

#include "LeetCode1803.h"

void LeetCode1803::add(int num) {
    Trie* curr = root;
    for (int k = HIGH_BIT; k >= 0; k--) {
        int bit = (num >> k) & 1;
        if (curr->son[bit] == nullptr) {
            curr->son[bit] = new Trie();
        }
        curr = curr->son[bit];
        curr->sum++;
    }
}

int LeetCode1803::get(int num, int x) {
    Trie* curr = root;
    int sum = 0;
    for (int k = HIGH_BIT; k >= 0; k--) {
        int r = (num >> k) & 1;
        if ((x >> k) & 1) {
            /**
             * x在第k位数字为1；
             */
            if (curr->son[r] != nullptr) {
                sum += curr->son[r]->sum;
            }
            if (curr->son[r ^ 1] == nullptr) {
                return sum;
            }
            curr = curr->son[r ^ 1];
        } else {
            if (curr->son[r] == nullptr) {
                return sum;
            }
            curr = curr->son[r];
        }
    }
    sum += curr->sum;
    return sum;
}

int LeetCode1803::f(vector<int> &nums, int x) {
    root = new Trie();
    int res = 0;
    for (int i = 1; i < nums.size(); i++) {
        add(nums[i - 1]);
        res += get(nums[i], x);
    }
}

int LeetCode1803::countPairs(vector<int> &nums, int low, int high) {
    return f(nums, high) - f(nums, low - 1);
}
