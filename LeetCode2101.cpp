//
// Created by luzehui on 2024/7/22.
//

#include "LeetCode2101.h"

#include <functional>

int LeetCode2101::maximumDetonation(vector<vector<int>> &bombs) {
    int n = bombs.size();
    vector<vector<long long>> grids(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                long long radius = pow((bombs[i][0] - bombs[j][0]), 2) + pow((bombs[i][1] - bombs[j][1]), 2);
                grids[i][j] = radius;
                grids[j][i] = radius;
            }
        }
    }
    int res = 1;
    std::function<int(int, vector<int>&, vector<int>&)> dfs = [&](int index, vector<int>& curr, vector<int>& visits) -> int {
        int temp = 1;
        for (int i = 0; i < n; i++) {
            if (visits[i] == 0 && grids[index][i] <= (long long)curr[2] * (long long)curr[2]) {
                visits[i] = 1;
                temp += dfs(i, bombs[i], visits);
            }
        }
        return temp;
    };
    for (int i = 0; i < n; i++) {
        vector<int> visits(n, 0);
        visits[i] = 1;
        res = max(res, dfs(i, bombs[i], visits));
    }
    return res;
}
