//
// Created by luzehui on 2023/12/11.
//

#include "LeetCode1631.h"

const vector<int> dirs = {-1, 0, 1, 0, -1};

int LeetCode1631::minimumEffortPath(vector<vector<int>> &heights) {
    int maxVal = 0;
    for (auto& height : heights) {
        maxVal = max(maxVal, *max_element(height.begin(), height.end()));
    }
    int left = 0, right = maxVal;
    int mid = (left + right) / 2;
    int m = heights.size();
    int n = heights[0].size();
    while (left < right) {
        vector<vector<int>> visits(m, vector<int>(n, 0));
        if (dfs(heights, visits, {0, 0}, {-1, -1}, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
        mid = (left + right) / 2;
    }
    return right;
}

bool LeetCode1631::dfs(vector<vector<int>> &heights, vector<vector<int>>& visits, pair<int, int> curr, pair<int, int> last, int target) {
    int currRow = curr.first, currCol = curr.second;
    int m = heights.size(), n = heights[0].size();
    if (currRow == m - 1 && currCol == n - 1) {
        return true;
    }
    visits[currRow][currCol] = 1;
    int lastRow = last.first, lastCol = last.second;
    for (int i = 0; i < 4; i++) {
        int nextRow = currRow + dirs[i], nextCol = currCol + dirs[i + 1];
        if (nextRow < 0 || nextRow >= m || nextCol < 0 || nextCol >= n ) {
            continue;
        }
        if (visits[nextRow][nextCol] == 1) {
            continue;
        }
        if (abs(heights[nextRow][nextCol] - heights[currRow][currCol]) <= target) {
            if (dfs(heights, visits, {nextRow, nextCol}, {currRow, currCol}, target)) {
                return true;
            }
        }
    }
    return false;
}
