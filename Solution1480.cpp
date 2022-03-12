//
// Created by luzh on 2021/8/28.
//

#include "Solution1480.h"

vector<int> Solution1480::runningSum(vector<int> &nums) {
    int curr = 0;
    int size = nums.size();
    vector<int> ans(size);
    for (int i = 0; i < size; i++) {
        curr += nums[i];
        ans[i] = curr;
    }
    return ans;
}
