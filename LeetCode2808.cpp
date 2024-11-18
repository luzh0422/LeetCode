//
// Created by luzehui on 2024/1/30.
//

#include "LeetCode2808.h"
#include <unordered_map>

int LeetCode2808::minimumSeconds(vector<int> &nums) {
    unordered_map<int, vector<int>> uM;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (uM.count(nums[i])) {
            uM[nums[i]].push_back(i);
        } else {
            uM.insert(unordered_map<int, vector<int>>::value_type(nums[i], {i}));
        }
    }
    int ans = INT_MAX;
    for (auto iter = uM.begin(); iter != uM.end(); iter++) {
        vector<int> values = iter->second;
        int mx = values[0] + n - values.back();
        for (int i = 0; i < values.size() - 1; i++) {
            mx = max(mx, values[i + 1] - values[i]);
        }
        ans = min(ans, mx / 2);
    }
   return ans;
}
