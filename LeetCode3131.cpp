//
// Created by luzehui on 2024/8/8.
//

#include "LeetCode3131.h"

int LeetCode3131::addedInteger(vector<int> &nums1, vector<int> &nums2) {
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());
    return nums2.front() - nums1.front();
}
