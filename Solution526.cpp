//
// Created by luzh on 2021/8/16.
//

#include "Solution526.h"

int Solution526::countArrangement(int n) {
    vector<vector<int>> matrix(n + 1);
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (i % j == 0 || j % i == 0) {
                matrix[i].push_back(j);
            }
        }
    }
    int ans = 0;
    vector<int> visit(n + 1, false);
    backtrack(1, n, ans, visit, matrix);
    return ans;
}

void Solution526::backtrack(int index, int n, int &ans, vector<int> &visit, vector<vector<int>> &matrix) {
    if (index == n + 1) {
        ans += 1;
        return;
    }
    for (auto& num: matrix[index]) {
        if (!visit[num]) {
            visit[num] = true;
            backtrack(index + 1, n, ans, visit, matrix);
            visit[num] = false;
        }
    }
}
