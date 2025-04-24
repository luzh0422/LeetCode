//
// Created by luzehui on 25-2-6.
//

#include "LeetCode47.h"

vector<vector<int>> LeetCode47::permuteUnique(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> curr{};
    vector<int> tag(n, 0);
    vector<vector<int>> res{};
    backtrack(nums, curr, tag, res);
    return res;
}

void LeetCode47::backtrack(vector<int> &nums, vector<int> &curr, vector<int> &tag, vector<vector<int>> &res) {
    if (curr.size() == nums.size()) {
        res.push_back(curr);
        return;
    }
    int index = 0;
    while (index < nums.size()) {
        if (!tag[index]) {
            curr.push_back(nums[index]);
            tag[index] = 1;
            backtrack(nums, curr, tag, res);
            curr.pop_back();
            tag[index] = 0;
            while (index < nums.size() - 1 && nums[index + 1] == nums[index]) {
                index++;
            }
        }
        index++;
    }
    return;
}
