//
// Created by luzh on 2022/3/9.
//

#include "LeetCode798.h"

int LeetCode798::bestRotation(vector<int> &nums) {
    int maxCore = 0;
    int step = 0;
    int ret = 0;
    int n = nums.size();
    while (step <= n / 2) {
        int backwardCore = 0;
        int forwardCore = 0;
        for (int i = 0; i < n; i++) {
            int backwardIndex = (i + n - step) % n;
            int forwardIndex = (i + step) % n;
            if (nums[i] <= backwardIndex) {
                backwardCore++;
            }
            if (nums[i] <= forwardIndex) {
                forwardCore++;
            }
        }
        if (backwardCore > maxCore || (backwardCore == maxCore && step < ret)) {
            ret = step;
            maxCore = backwardCore;
        }
        if (forwardCore > maxCore || (forwardCore == maxCore && n - step < ret)) {
            ret = n - step;
            maxCore = forwardCore;
        }
        step++;
    }
    return ret;
}
