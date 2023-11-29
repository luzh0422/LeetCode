//
// Created by 陆泽辉 on 2022/12/20.
//

#include "LeetCode1760.h"

int LeetCode1760::minimumSize(vector<int> &nums, int maxOperations) {
    int left = 1, right = *max_element(nums.begin(), nums.end());
    int ans = -1;
    while (left <= right) {
        int temp = 0, middle = (left + right) / 2;
        for (int num : nums) {
            if (num > middle) {
                temp += (num - 1) / middle;
            }
        }
        if (temp <= maxOperations) {
            ans = middle;
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    return ans;
}
