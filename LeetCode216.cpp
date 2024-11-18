//
// Created by luzehui on 2024/4/21.
//

#include "LeetCode216.h"
#include <cmath>

vector<vector<int>> LeetCode216::combinationSum3(int k, int n) {
    vector<vector<int>> res{};
    for (int i = 1; i <= 9; i++) {
        vector<int> curr{};
        curr.push_back(i);
        combinationSum3(k - 1, n, res, curr, i, i);
    }
    return res;
}

void LeetCode216::combinationSum3(int k, int n, vector<vector<int>> &res, vector<int>& curr, int total, int start) {
    if (total == n && k == 0) {
        res.push_back(curr);
    }
    if (total > n || k == 0) {
        return;
    }
    for (int i = start + 1; i <= 9; i++) {
        curr.push_back(i);
        combinationSum3(k - 1, n, res, curr, total + i, i);
        curr.pop_back();
    }
    return;
}


