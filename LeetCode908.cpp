//
// Created by 陆泽辉 on 2022/4/30.
//

#include "LeetCode908.h"

int LeetCode908::smallestRangeI(vector<int> &nums, int k) {
    int maxNum = *max_element(nums.begin(), nums.end());
    int minNum = *min_element(nums.begin(), nums.end());
    if (maxNum - minNum <= 2 * k) {
        return 0;
    } else {
        return maxNum - minNum - 2 * k;
    }
}
