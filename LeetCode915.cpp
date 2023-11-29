//
// Created by 陆泽辉 on 2022/10/24.
//

#include "LeetCode915.h"

int LeetCode915::partitionDisjoint(vector<int> &nums) {
    int n = nums.size();
    vector<int> maxNums(n, 0);
    vector<int> minNums(n, 0);
    maxNums[0] = nums[0];
    for (int i = 1; i < n; i++) {
        maxNums[i] = max(maxNums[i - 1], nums[i]);
    }
    minNums[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        minNums[i] = min(minNums[i + 1], nums[i]);
    }
    int index = 0;
    int ret = 0;
    while (index < n - 1) {
        if (maxNums[index] <= minNums[index + 1]) {
            ret = index + 1;
            break;
        }
        index++;
    }
    return ret;
}
