//
// Created by 陆泽辉 on 2023/2/27.
//

#include "LeetCode1144.h"

int LeetCode1144::movesToMakeZigzag(vector<int> &nums) {
    /**
     * odd
     */
    int n = nums.size();
    int oddRes = 0;
    vector<int> copyNums(nums.begin(), nums.end());
    for (int i = 1; i < n; i += 2) {
        int temp = copyNums[i - 1];
        if (i + 1 < n) {
            temp = min(temp, copyNums[i + 1]);
        }
        if (temp - 1 < copyNums[i]) {
            oddRes += copyNums[i] - temp + 1;
            copyNums[i] = temp - 1;
        }
    }
    /**
     * even
     */
    copyNums.assign(nums.begin(), nums.end());
    int evenRes = 0;
    for (int i = 0; i < n; i += 2) {
        int temp = INT_MAX;
        if (i - 1 > 0) {
            temp = copyNums[i - 1];
        }
        if (i + 1 < n) {
            temp = min(temp, copyNums[i + 1]);
        }
        if (temp - 1 < copyNums[i]) {
            evenRes += copyNums[i] - temp + 1;
            copyNums[i] = temp - 1;
        }
    }
    return min(oddRes, evenRes);
}
