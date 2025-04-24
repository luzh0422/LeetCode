//
// Created by luzehui on 25-1-30.
//

#include "LeetCode350.h"

vector<int> LeetCode350::intersect(vector<int> &nums1, vector<int> &nums2) {
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());
    int index1 = 0, index2 = 0, n1 = nums1.size(), n2 = nums2.size();
    vector<int> res{};
    while (index1 < n1 && index2 < n2) {
        if (nums1[index1] == nums2[index2]) {
            res.push_back(nums1[index1]);
            index1++;
            index2++;
        } else if (nums1[index1] < nums2[index2]) {
            index1++;
        } else {
            index2++;
        }
    }
    return res;
}
