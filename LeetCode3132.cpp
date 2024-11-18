//
// Created by luzehui on 2024/8/9.
//

#include "LeetCode3132.h"

#include <unordered_map>

int LeetCode3132::minimumAddedInteger(vector<int> &nums1, vector<int> &nums2) {
    std::sort(nums1.begin(), nums1.end(), greater<int>());
    std::sort(nums2.begin(), nums2.end(), greater<int>());
    int index1 = 0, res = INT_MAX;
    size_t n1 = nums1.size();
    while (index1 < n1) {
        int index3 = index1 + 1;
        int index2 = 1;
        int target = nums2[0] - nums1[index1];
        while (index3 < n1 && index2 < n1 - 2) {
            if (nums2[index2] - nums1[index3] == target) {
                index2++;
            }
            index3++;
        }
        if (index2 == n1 - 2) {
            res = min(target, res);
        }
        index1++;
    }
    return res;
}
