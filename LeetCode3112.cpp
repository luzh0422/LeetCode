//
// Created by luzehui on 2024/7/18.
//

#include "LeetCode3112.h"
#include <queue>

vector<int> LeetCode3112::minimumTime(int n, vector<vector<int>> &edges, vector<int> &disappear) {
    vector<vector<pair<int, int>>> g(n);
    for (auto& e : edges) {
        int u = e[0], v = e[1], w = e[2];
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    vector<int> dis(n, INT_MAX);
    dis[0] = 0;
    /**
     * 利用优先队列求解Dijkstra距离；
     */
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, 0);
    while (!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();
        if (du > dis[u])
            continue;
        for (auto& [v, w] : g[u]) {
            int dv = du + w;
            /**
             * 必须确保到达这个顶点的最小距离小于disappear的距离，这个顶点才能被访问到，才能更新到dijkstra距离中；
             */
            if (dv < dis[v] && dv < disappear[v]) {
                dis[v] = dv;
                pq.emplace(dv, v);
            }
        }
    }
    for (int& e : dis) {
        if (e == INT_MAX) {
            e = -1;
        }
    }
    return dis;
}

void LeetCode3112::dijkstra(int n, vector<vector<int>> &edges, vector<int> &distances) {
    vector<bool> vis(n, false);
    distances[0] = 0;
    vis[0] = true;
    for (int i = 1; i < n; i++) {
        int k = -1;
        for(int j = 0; j < n; j++)
            if(!vis[j] && (k == -1 || distances[k]>distances[j]))
                k = j;
        if (k == -1) {
            break;
        }
        vis[k] = true;
        for(int j = 0;j < n;j++)//松弛操作
            if(!vis[j] && distances[j] > distances[k] + edges[k][j])
                distances[j] = distances[k] + edges[k][j];
    }
    return;
}
