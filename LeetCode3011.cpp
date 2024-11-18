//
// Created by luzehui on 2024/7/13.
//

#include "LeetCode3011.h"
#include <functional>

bool LeetCode3011::canSortArray(vector<int> &nums) {
    function<int(int)> getOneBitCount = [&](int num) -> int {
        int res = 0;
        while (num != 0) {
            if ((num & 1) == 1) {
                res++;
            }
            num >>= 1;
        }
        return res;
    };
    int n = nums.size();
    vector<int> maxNums(n, 0);
    vector<int> steps(n, 0);
    maxNums[0] = nums[0], steps[0] = 1;
    int currOneBitCount = getOneBitCount(nums[0]);
    for (int i = 1; i < n; i++) {
        int oneBitCount = getOneBitCount(nums[i]);
        if (oneBitCount != currOneBitCount) {
            if (nums[i] < maxNums[i - 1]) {
                return false;
            }
            maxNums[i] = nums[i];
            steps[i] = 1;
            currOneBitCount = oneBitCount;
        } else {
            if (i - steps[i - 1] != 0 && nums[i] < maxNums[i - steps[i - 1] - 1]) {
                return false;
            }
            steps[i] = steps[i - 1] + 1;
            maxNums[i] = max(nums[i], maxNums[i - 1]);
        }
    }
    return true;
}
