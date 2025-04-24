//
// Created by luzehui on 25-2-5.
//

#include "LeetCode90.h"

vector<vector<int>> LeetCode90::subsetsWithDup(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    vector<int> currArr{};
    vector<vector<int>> res{};
    backtrack(nums, currArr, res, 0);
    return res;
}

void LeetCode90::backtrack(vector<int> &nums, vector<int> &currArr, vector<vector<int>> &res, int index) {
    res.push_back(currArr);
    if (index >= nums.size()) {
        return;
    }
    currArr.push_back(nums[index]);
    backtrack(nums, currArr, res, index + 1);
    currArr.pop_back();
    for (int i = index + 1; i < nums.size(); i++) {
        if (nums[i] != nums[i - 1]) {
            currArr.push_back(nums[i]);
            backtrack(nums, currArr, res, i + 1);
            currArr.pop_back();
        }
    }
    return;
}
