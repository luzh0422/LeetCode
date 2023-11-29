//
// Created by 陆泽辉 on 2023/9/5.
//

#include "LeetCode2605.h"
#include <unordered_set>

int LeetCode2605::minNumber(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> s1, s2;
    int min1 = INT_MAX, min2 = INT_MAX;
    for (auto num: nums1) {
        s1.insert(num);
        min1 = min(min1, num);
    }
    int res = 10;
    for (auto num : nums2) {
        if (s1.count(num)) {
            res = min(res, num);
        }
        s2.insert(num);
        min2 = min(min2, num);
    }
    return res == 10 ? min(min1, min2) * 10 + max(min1, min2) : res;
}
