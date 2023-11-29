//
// Created by 陆泽辉 on 2023/7/4.
//

#include "LeetCode2679.h"

int LeetCode2679::matrixSum(vector<vector<int>> &nums) {
    for (auto& subarr : nums) {
        std::sort(subarr.begin(), subarr.end());
    }
    int res = 0;
    int row = nums.size(), col = nums[0].size();
    for (int i = 0; i < col; i++) {
        int num = 0;
        for (int j = 0; j < row; j++) {
            num = max(num, nums[j][i]);
        }
        res += num;
    }
    return res;
}
