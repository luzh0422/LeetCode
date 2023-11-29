//
// Created by 陆泽辉 on 2023/5/13.
//

#include "LeetCode2441.h"

#include <unordered_set>

int LeetCode2441::findMaxK(vector<int> &nums) {
    unordered_set<int> uS;
    int res = -1;
    for (auto num : nums) {
        uS.insert(num);
        int temp = -num;
        if (uS.count(temp)) {
            res = max(res, abs(num));
        }
    }
    return res;
}
