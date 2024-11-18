//
// Created by luzehui on 2024/4/12.
//

#include "LeetCode2923.h"

int LeetCode2923::findChampion(vector <vector<int>> &grid) {
    int n = grid.size();
    vector<int> indegrees(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (grid[i][j] == 1) {
                    indegrees[j]++;
                } else {
                    indegrees[i]++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (indegrees[i] == 0) {
            return i;
        }
    }
    return -1;
}
