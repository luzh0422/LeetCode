//
// Created by luzh on 2021/4/5.
//

#include "Solution88.h"

void Solution88::merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    nums1.resize(m);
    nums2.resize(n);
    vector<int> ans(m + n);
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (nums1[i] <= nums2[j]) {
            ans[i + j] = nums1[i];
            i++;
        } else {
            ans[i + j] = nums2[j];
            j++;
        }
    }
    while (i < m) {
        ans[i + j] = nums1[i];
        i++;
    }
    while (j < n) {
        ans[i + j] = nums2[j];
        j++;
    }
    nums1 = ans;
}
