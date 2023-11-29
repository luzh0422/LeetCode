//
// Created by 陆泽辉 on 2022/9/19.
//

#include "LeetCode1636.h"
#include <unordered_map>

vector<int> LeetCode1636::frequencySort(vector<int> &nums) {
    unordered_map<int, int> records = {};
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (records.count(nums[i])) {
            records[nums[i]]++;
        } else {
            records.insert(unordered_map<int, int>::value_type (nums[i], 1));
        }
    }
    vector<pair<int, int>> cache(records.begin(), records.end());
    std::sort(cache.begin(), cache.end(), [](pair<int, int>& num1, pair<int, int >& num2) -> bool {
       if (num1.second > num2.second) {
           return true;
       } else if (num1.second == num2.second) {
           return num1.first >= num2.first;
       } else {
           return false;
       }
    });
    vector<int> ret = {};
    for (auto it = cache.begin(); it != cache.end(); ++it) {
        for (int i = 0; i < it->second; i++) {
            ret.emplace_back(it->first);
        }
    }
    return ret;
}
