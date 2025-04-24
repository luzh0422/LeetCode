//
// Created by luzehui on 2024/11/19.
//

#include "LeetCode3243.h"
#include <queue>
#include <string.h>

vector<int> LeetCode3243::shortestDistanceAfterQueries(int n, vector<vector<int>> &queries) {
    vector<vector<int>> graph(n, vector<int>{});
    for (int i = 0; i < n - 1; i++) {
        graph[i].push_back(i + 1);
    }
    int distance[n];
    memset(distance, 0x3f, sizeof(distance));
    int edge[2] = {0, 0};
    dijkstra(graph, distance, edge);
    vector<int> res;
    for (auto &query : queries) {
        int start = query[0], end = query[1];
        graph[start].push_back(end);
        int edge[2] = { distance[start], start};
        dijkstra(graph, distance, edge);
        res.push_back(distance[n - 1]);
    }
    return res;
}

void LeetCode3243::dijkstra(vector<vector<int>> &graph, int* distance, int* edge) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(edge[0], edge[1]);
    while (!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();
        if (du > distance[u])
            continue;
        distance[u] = du;
        for (auto& v : graph[u]) {
            int dv = du + 1;
            if (dv < distance[v]) {
                distance[v] = dv;
                pq.emplace(dv, v);
            }
        }
    }
}
