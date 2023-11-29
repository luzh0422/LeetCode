//
// Created by 陆泽辉 on 2023/7/1.
//

#include "LeetCode1.h"
#include <unordered_map>

vector<int> LeetCode1::twoSum(vector<int> &nums, int target) {
    unordered_map<int, vector<int>> um{};
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int num = nums[i];
        if (um.count(num)) {
            um[num].push_back(i);
        } else {
            um.insert(unordered_map<int, vector<int>>::value_type(num, {i}));
        }
    }
    vector<int> res;
    for (int i = 0; i < n; i++) {
        int delta = target - nums[i];
        if (um.count(delta)) {
            if (um[delta].front() == i && um[delta].size() > 1) {
                return um[delta];
            }
            if (um[delta].front() != i) {
                res.push_back(i);
                res.push_back(um[delta].front());
                return res;
            }
        }
    }
    return {};
}
