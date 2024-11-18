//
// Created by luzehui on 2024/5/23.
//

#include "LeetCode2831.h"

#include <unordered_map>

/**
 * 哈希表内的滑动窗口
 * @param nums
 * @param k
 * @return
 */
int LeetCode2831::longestEqualSubarray(vector<int> &nums, int k) {
    unordered_map<int, vector<int>> uM;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (uM.count(nums[i])) {
            uM[nums[i]].push_back(i);
        } else {
            uM.emplace(nums[i], 0);
            uM[nums[i]].push_back(i);
        }
    }
    int res = 0;
    for (auto iter = uM.begin(); iter != uM.end(); iter++) {
        auto& temp = iter->second;
        int l = 0, r = 0;
        while (r < temp.size()) {
            while (r < temp.size() && (temp[r] - temp[l]) - (r - l) <= k) {
                r++;
            }
            res = max(res, r - l);
            l++;
            r++;
        }
    }
    return res;
}

