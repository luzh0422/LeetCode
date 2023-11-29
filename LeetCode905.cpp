//
// Created by 陆泽辉 on 2022/4/28.
//

#include "LeetCode905.h"

vector<int> LeetCode905::sortArrayByParity(vector<int> &nums) {
    int oddIndex = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] % 2 == 0) {
            int temp = nums[i];
            nums[i] = nums[oddIndex];
            nums[oddIndex] = temp;
            oddIndex++;
        }
    }
    return nums;
}
