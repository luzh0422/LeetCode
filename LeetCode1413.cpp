//
// Created by 陆泽辉 on 2022/8/9.
//

#include "LeetCode1413.h"

int LeetCode1413::minStartValue(vector<int> &nums) {
    int minVal = 0;
    int curr = 0;
    for (auto& num : nums) {
        curr += num;
        minVal = min(minVal, curr);
    }
    if (minVal >= 0) {
        return 1;
    } else {
        return abs(minVal) + 1;
    }
}
