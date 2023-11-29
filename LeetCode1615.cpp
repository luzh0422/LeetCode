//
// Created by 陆泽辉 on 2023/3/15.
//

#include "LeetCode1615.h"

int LeetCode1615::maximalNetworkRank(int n, vector<vector<int>> &roads) {
    vector<int> degree(n, 0);
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (auto road : roads) {
        int first = road[0], second = road[1];
        degree[first]++;
        degree[second]++;
        graph[first][second] = 1;
        graph[second][first] = 1;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            int temp = degree[i] + degree[j];
            if (graph[i][j]) {
                temp -= 1;
            }
            res = max(temp, res);
        }
    }
    return res;
}
