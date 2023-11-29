//
// Created by 陆泽辉 on 2023/8/13.
//

#include "LeetCode88.h"

void LeetCode88::merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    vector<int> nums3(nums1.begin(), nums1.begin() + m);
    int i = 0, j = 0;
    int index = 0;
    while (i < m && j < n) {
        if (nums3[i] < nums2[j]) {
            nums1[index] = nums3[i];
            i++;
        } else {
            nums1[index] = nums2[j];
            j++;
        }
        index++;
    }
    while (i < m) {
        nums1[index] = nums3[i];
        i++;
        index++;
    }
    while (j < n) {
        nums1[index] = nums2[j];
        j++;
        index++;
    }
    return;
}
