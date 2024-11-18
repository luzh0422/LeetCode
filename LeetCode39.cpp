//
// Created by luzehui on 2024/4/21.
//

#include "LeetCode39.h"

vector<vector<int>> LeetCode39::combinationSum(vector<int> &candidates, int target) {
    vector<int> curr{};
    vector<vector<int>> res{};

    return res;
}

void LeetCode39::combinationSum(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &curr, int currTotal, int startIndex) {
    if (currTotal == target) {
        res.push_back(curr);
        return;
    }
    if (currTotal > target) {
        return;
    }
    int n = candidates.size();
    for (int i = startIndex; i < n; i++) {
        int candidate = candidates[i];
        curr.push_back(candidate);
        combinationSum(candidates, target, res, curr, currTotal + candidate, i);
        curr.pop_back();
    }
}
