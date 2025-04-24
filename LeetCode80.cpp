//
// Created by luzehui on 25-2-9.
//

#include "LeetCode80.h"

int LeetCode80::removeDuplicates(vector<int> &nums) {
    int left = 0, right = 0, index = 0, n = nums.size(), curr = nums[0], count = 0;
    while (index + count < n) {
        if (curr == nums[index]) {
            right = index++;
        } else {
            if (right - left >= 2) {
                int temp = right - left - 1;
                for (int i = left + 2; i < n && i + temp < n; i++) {
                    nums[i] = nums[i + temp];
                }
                count += temp;
                left += 2;
                right = left;
                index = left;
                curr = nums[index];
            } else {
                left = index;
                right = index;
                curr = nums[index++];
            }
        }
    }
    if (right - left >= 2) {
        int temp = right - left - 1;
        count += temp;
    }
    return n - count;
}
