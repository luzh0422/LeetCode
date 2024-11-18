//
// Created by luzehui on 2024/7/16.
//

#include "LeetCode2956.h"

#include <unordered_set>

vector<int> LeetCode2956::findIntersectionValues(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> uS1, uS2;
    vector<int> arr;
    for (auto num : nums1) {
        uS1.insert(num);
    }
    int count1 = 0, count2 = 0;
    for (auto num : nums2) {
        uS2.insert(num);
        if (uS1.count(num)) {
            count2++;
        }
    }
    for (auto num : nums1) {
        if (uS2.count(num)) {
            count1++;
        }
    }
    arr.push_back(count1);
    arr.push_back(count2);
    return arr;
}
