//
// Created by luzehui on 2024/4/30.
//

#include "LeetCode2798.h"

int LeetCode2798::numberOfEmployeesWhoMetTarget(vector<int> &hours, int target) {
    std::sort(hours.begin(), hours.end());
    auto iter = lower_bound(hours.begin(), hours.end(), target);
    return distance(iter, hours.end());
}
