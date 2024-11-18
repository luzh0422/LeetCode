//
// Created by luzehui on 2024/4/13.
//

#include "LeetCode2924.h"

int LeetCode2924::findChampion(int n, vector<vector<int>> &edges) {
    vector<int> indegrees(n, 0);
    for (auto& edge : edges) {
        indegrees[edge[1]]++;
    }
    int index = -1, count = 0;
    for (int i = 0; i < n; i++) {
        if (indegrees[i] == 0) {
            index = i;
            count++;
        }
    }
    if (count == 0 || count > 1) {
        return -1;
    }
    return index;
}
