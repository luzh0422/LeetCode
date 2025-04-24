//
// Created by luzehui on 2024/11/25.
//

#include "LeetCode743.h"
#include <queue>

int LeetCode743::networkDelayTime(vector<vector<int>> &times, int n, int k) {
    vector<vector<pair<int, int>>> g(n + 1, vector<pair<int, int>>{});
    for (auto& time : times) {
        g[time[0]].push_back({time[1], time[2]});
    }
    vector<int> distances(n + 1, -1);
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, k);
    while (pq.empty()) {
        int d = pq.top().first, n = pq.top().second;
        distances[n] = d;
        pq.pop();
        for (auto &edge : g[n]) {
            int next = edge.first, nextD = edge.second;
            if (distances[next] == -1 || d + nextD < distances[next]) {
                pq.emplace(d + nextD, next);
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n + 1; i++) {
        res = max(res, distances[i]);
    }
    return res;
}
