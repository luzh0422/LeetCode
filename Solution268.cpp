//
// Created by luzh on 2021/11/6.
//

#include "Solution268.h"
#include <unordered_map>

int Solution268::missingNumber(vector<int> &nums) {
    unordered_map<int, int> uM;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        uM[nums[i]] = 1;
    }
    for (int i = 0; i <= n; i++) {
        if (!uM.count(i)) {
            return i;
        }
    }
    return -1;
}
