//
// Created by luzh on 2021/7/14.
//

#include "Solution1818.h"

int Solution1818::minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2) {
    const int mod = 1000000007;
    vector<int> rec(nums1);
    std::sort(rec.begin(), rec.end());
    int sum = 0, maxn = 0;
    int size = nums1.size();
    for (int i = 0; i < size; i++) {
        int diff = abs(nums1[i] - nums2[i]);
        sum = (sum + diff) % mod;
        int index = std::lower_bound(rec.begin(), rec.end(), nums2[i]) - rec.begin();
        if  (index < size) {
            maxn = max(maxn, diff - (rec[index] - nums2[i]));
        }
        if (index > 0) {
            maxn = max(maxn, diff - (nums2[i] - rec[index - 1]));
        }
    }
    return (sum - maxn + mod) % mod;
}
