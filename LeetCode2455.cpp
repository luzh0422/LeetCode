//
// Created by 陆泽辉 on 2023/5/29.
//

#include "LeetCode2455.h"

int LeetCode2455::averageValue(vector<int> &nums) {
    int total = 0, count = 0;
    for (auto num : nums) {
        if (num % 6 == 0) {
            total += num;
            count += 1;
        }
    }
    return total / count;
}
