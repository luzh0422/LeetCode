//
// Created by luzehui on 25-1-26.
//

#include "LeetCode40.h"

vector<vector<int>> LeetCode40::combinationSum2(vector<int> &candidates, int target) {
    vector<int> curr = {};
    vector<vector<int>> res = {};
    std::sort(candidates.begin(), candidates.end());
    combinationSum2(candidates, target, 0, curr, res, 0);
    return res;
}

void LeetCode40::combinationSum2(vector<int> &candidates, int target, int total, vector<int> &curr, vector<vector<int>> &res, int index) {
    int n = candidates.size();
    if (total == target) {
        res.push_back(curr);
        return;
    }
    if (total > target || index >= n) {
        return;
    }
    curr.push_back(candidates[index]);
    combinationSum2(candidates, target, total + candidates[index], curr, res, index + 1);
    curr.pop_back();
    for (int i = index + 1; i < n; i++) {
        if (candidates[i] != candidates[i - 1]) {
            curr.push_back(candidates[i]);
            combinationSum2(candidates, target, total + candidates[i], curr, res, i + 1);
            curr.pop_back();
        }
    }
}
