//
// Created by 陆泽辉 on 2022/10/8.
//

#include "LeetCode870.h"

namespace {
    int binarySearch(vector<int>& nums, vector<bool>& visits, int num) {
        int left = 0, right = nums.size() - 1;
        return 0;
    }
}

vector<int> LeetCode870::advantageCount(vector<int> &nums1, vector<int> &nums2) {
    std::sort(nums1.begin(), nums1.end());
    int n = nums1.size();
    vector<int> ret;
    vector<bool> visit(n, false);
    for (int i = 0; i < n; i++) {
        int num = nums2[i];
        int j = 0;
        for (; j < n; j++) {
            if (!visit[j] && nums1[j] > num) {
                break;
            }
        }
        if (j == n) {
            for (int k = 0; k < n; k++) {
                if (!visit[k]) {
                    ret.push_back(nums1[k]);
                    visit[k] = true;
                    break;
                }
            }
        } else {
            ret.push_back(nums1[j]);
            visit[j] = true;
        }
    }
    return ret;
}
