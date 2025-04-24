//
// Created by luzehui on 24-12-11.
//

#include "LeetCode2717.h"

int LeetCode2717::semiOrderedPermutation(vector<int> &nums) {
    int oneIndex = -1, nIndex = -1, n = nums.size();
    for (int i = 0; i <  n; i++) {
        if (nums[i] == 1) {
            oneIndex = i;
            if (nIndex != -1) {
                break;
            }
        } else if (nums[i] == n) {
            nIndex = i;
            if (oneIndex != -1) {
                break;
            }
        }
    }
    int res = oneIndex + (n - nIndex - 1);
    if (nIndex < oneIndex) {
        res--;
    }
    return res;
}
