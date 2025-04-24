//
// Created by luzehui on 25-2-4.
//

#include "LeetCode922.h"

vector<int> LeetCode922::sortArrayByParityII(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if ((nums[i] & 1) == 0 && (i & 1) == 1) {
            for (int j = i + 1; j < n; j++) {
                if ((nums[j] & 1) == 1 && (j & 1) == 0) {
                    int temp = nums[j];
                    nums[j] = nums[i];
                    nums[i] = temp;
                }
            }
        } else if ((nums[i] & 1) == 1 && (i & 1) == 0) {
            for (int j = i + 1; j < n; j++) {
                if ((nums[j] & 1) == 0 && (j & 1) == 1) {
                    int temp = nums[j];
                    nums[j] = nums[i];
                    nums[i] = temp;
                }
            }
        }
    }
    return nums;
}
