//
// Created by luzehui on 2024/4/27.
//

#include "LeetCode2639.h"
#include <string>
#include <algorithm>

vector<int> LeetCode2639::findColumnWidth(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<int> ans(m, 0);
    for (int i = 0; i < m; i++) {
        int curr = 0;
        for (int j = 0; j < n; j++) {
            string s = to_string(grid[j][i]);
            curr = max(curr, (int)s.size());
        }
        ans[i] = curr;
    }
    return ans;
}
