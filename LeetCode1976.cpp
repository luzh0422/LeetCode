//
// Created by luzehui on 2024/3/5.
//

#include "LeetCode1976.h"

int LeetCode1976::countPaths(int n, vector<vector<int>> &roads) {
    const int MOD = 1e9 + 7;
    vector<vector<long long>> graph(n, vector<long long>(n, -1));
    for (auto& road : roads) {
        int x = road[0], y = road[1], d = road[2];
        graph[x][y] = d;
        graph[y][x] = d;
    }
    vector<long long> distances(n, LLONG_MAX);
    vector<int> dp(n, 0);
    vector<bool> visits(n, false);
    distances[0] = 0;
    dp[0] = 1;
    int target = 0;
    while (true) {
        long long currDistance = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            if (!visits[i] && distances[i] < currDistance) {
                target = i;
                currDistance = distances[i];
            }
        }
        if (target == n - 1) {
            return dp[n - 1];
        }
        visits[target] = true;
        for (int i = 0; i < n; i++) {
            if (graph[target][i] != -1) {
                if (distances[target] + graph[target][i] < distances[i]) {
                    distances[i] = distances[target] + graph[target][i];
                    dp[i] = dp[target] % MOD;
                    dp[i] %= MOD;
                } else if (distances[target] + graph[target][i] == distances[i]) {
                    dp[i] += dp[target] % MOD;
                    dp[i] %= MOD;
                }
            }
        }
    }
}
