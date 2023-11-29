//
// Created by 陆泽辉 on 2022/12/7.
//

#include "LeetCode1775.h"
#include <numeric>

int LeetCode1775::minOperations(vector<int> &nums1, vector<int> &nums2) {
    int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
    int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
    int diff = sum1 - sum2;
    if (diff == 0) {
        return 0;
    }
    if (diff < 0) {
        swap(nums1, nums2);
        swap(sum1, sum2);
    }
    vector<int> ant(7, 0);
    int n = nums1.size(), m = nums2.size();
    diff = sum1 - sum2;
    for (int i = 0; i < n; i++) {
        ant[nums1[i] - 1]++;
    }
    for (int i = 0; i < m; i++) {
        ant[6 - nums2[i]]++;
    }
    int ret = 0;
    for (int i = 6; i > 0; i--) {
        while (ant[i] != 0) {
            ret++;
            diff -= i;
            if (diff <= 0) {
                return ret;
            }
            ant[i]--;
        }
    }
    return -1;
}
