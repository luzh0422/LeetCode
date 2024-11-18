//
// Created by luzehui on 2024/6/15.
//

#include "LeetCode2779.h"

int LeetCode2779::maximumBeauty(vector<int> &nums, int k) {
//    std::sort(nums.begin(), nums.end());
//    int res = 1;
//    for (int i = 1; i < nums.size(); i++) {
//        int j = i - 1;
//        while (j >= 0 && nums[i] - nums[j] <= 2 * k) {
//            j--;
//        }
//        res = max(res, i - j);
//    }
//    return res;
    std::sort(nums.begin(), nums.end());
    int res = 1;
    for (int i = 1, j = 0; i < nums.size(); i++) {
        while (j < i && nums[i] - nums[j] > k + k) {
            j++;
        }
        res = max(i - j + 1, res);
    }
    return res;
}
