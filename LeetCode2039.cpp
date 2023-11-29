//
// Created by 陆泽辉 on 2022/3/20.
//

#include "LeetCode2039.h"
#include "queue"

int LeetCode2039::networkBecomesIdle(vector<vector<int>> &edges, vector<int> &patience) {
    int n = patience.size();
    int edgesSize = edges.size();
    vector<vector<int>> graph(n);
    vector<int> dis(n, -1);
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    dis[0] = 0;
    int maxDis = 0;
    for (int i = 0; i < edgesSize; i++) {
        graph[edges[i][0]].emplace_back(edges[i][1]);
        graph[edges[i][1]].emplace_back(edges[i][0]);
    }
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        int currNode = curr.first;
        int currDis = curr.second;
//        for (int i = 0; i < edgesSize; i++) {
//            if (edges[i][0] == currNode && dis[edges[i][1]] == -1) {
//                dis[edges[i][1]] = currDis + 1;
//                q.emplace(edges[i][1], currDis + 1);
//            }
//            if (edges[i][1] == currNode && dis[edges[i][0]] == -1) {
//                dis[edges[i][0]] = currDis + 1;
//                q.emplace(edges[i][0], currDis + 1);
//            }
//        }
        for (int i = 0; i < graph[currNode].size(); i++) {
            if (dis[graph[currNode][i]] == -1) {
                dis[graph[currNode][i]] = currDis + 1;
                q.emplace(graph[currNode][i], currDis + 1);
            }
        }
        if (patience[currNode] != 0) {
            int time = patience[currNode] * ((2 * currDis - 1) / patience[currNode]) + 2 * currDis + 1;
            maxDis = max(maxDis, time);
        }
    }
    return maxDis + 1;
}
