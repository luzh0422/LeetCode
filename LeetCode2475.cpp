//
// Created by 陆泽辉 on 2023/6/13.
//

#include "LeetCode2475.h"

int LeetCode2475::unequalTriplets(vector<int> &nums) {
    int n = nums.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        int a = nums[i];
        for (int j = i + 1; j < n; j++) {
            if (nums[j] == a) {
                continue;
            }
            int b = nums[j];
            for (int k = j + 1; k < n; k++) {
                if (nums[k] == a || nums[k] == b) {
                    continue;
                }
                res++;
            }
        }
    }
    return res;
}
