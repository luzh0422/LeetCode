//
// Created by luzehui on 25-4-2.
//

#include "LeetCode2873.h"

long long LeetCode2873::maximumTripletValue(vector<int> &nums) {
    long long res = 0ll;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                res = max(res, (long long)(nums[i] - nums[j]) * nums[k]);
            }
        }
    }
    return res;
}
