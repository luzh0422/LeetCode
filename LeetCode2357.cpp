//
// Created by 陆泽辉 on 2023/2/24.
//

#include "LeetCode2357.h"

int LeetCode2357::minimumOperations(vector<int> &nums) {
    vector<int> temp;
    int res = 0;
    while (nums.size() != 0) {
        int minVal = INT_MAX;
        temp.clear();
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                temp.push_back(nums[i]);
                minVal = min(minVal, nums[i]);
            }
        }
        nums = temp;
        if (nums.size() == 0) {
            break;
        }
        for (int i = 0; i < nums.size(); i++) {
            nums[i] -= minVal;
        }
        res++;
    }
    return res;
}
