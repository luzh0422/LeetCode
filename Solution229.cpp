//
// Created by luzh on 2021/10/22.
//

#include "Solution229.h"

#include <unordered_map>

vector<int> Solution229::majorityElement(vector<int> &nums) {
    unordered_map<int, int> uM;
    for (auto num : nums) {
        if (uM.count(num)) {
            uM[num]++;
        } else {
            uM[num] = 1;
        }
    }
    int n = nums.size() / 3;
    vector<int> ans;
    for (auto value : uM) {
        if (value.second >= n) {
            ans.push_back(value.first);
        }
    }
    return ans;
}
