//
// Created by 陆泽辉 on 2023/8/26.
//

#include "LeetCode228.h"

vector<string> LeetCode228::summaryRanges(vector<int> &nums) {
    if (nums.empty()) {
        return {};
    }
    int left = nums[0];
    int right = left;
    vector<string> res;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1] + 1) {
            right = nums[i - 1];
            if (left == right) {
                res.push_back(to_string(left));
            } else {
                res.push_back(to_string(left) + "->" + to_string(right));
            }
            left = nums[i];
            right = left;
        }
    }
    right = nums.back();
    if (left == right) {
        res.push_back(to_string(left));
    } else {
        res.push_back(to_string(left) + "->" + to_string(right));
    }
    return res;
}
