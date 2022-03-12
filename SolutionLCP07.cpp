//
// Created by luzh on 2021/7/1.
//

#include "SolutionLCP07.h"

#include <queue>

int SolutionLCP07::numWays(int n, vector<vector<int>> &relation, int k) {
    pair<int, int> steps;
    vector<vector<int>> graph(n, vector<int>(n, -1));
    for (auto& rl : relation) {
        graph[rl[0]][rl[1]] = 1;
    }

    queue<pair<int, int>> q;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (graph[0][i] == 1) {
            q.push({i, 1});
        }
    }
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        if (node.second > k) {
            break;
        }
        if (node.first == n && node.second == k) {
            ans += 1;
        }
        for (int i = 0; i < n; i++) {
            if (graph[node.first][i] == 1) {
                q.push({i, node.second + 1});
            }
        }
    }
    return ans;
}
