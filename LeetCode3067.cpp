//
// Created by luzehui on 2024/6/4.
//

#include "LeetCode3067.h"
#include <functional>

vector<int> LeetCode3067::countPairsOfConnectableServers(vector<vector<int>> &edges, int signalSpeed) {
    int n = edges.size() + 1;
    vector<vector<pair<int, int>>> graph(n);

    // 邻接矩阵构建图的时候，不要把无连接的节点插入到矩阵中；
    for (auto e : edges) {
        graph[e[0]].emplace_back(e[1], e[2]);
        graph[e[1]].emplace_back(e[0], e[2]);
    }

    // dfs不需要visitors判断，只需要与前一个节点判断即可；
    function<int(int, int, int)> dfs = [&](int p, int root, int curr) -> int {
        int res = 0;
        if (curr == 0) {
            res++;
        }
        for (auto &[v, cost] : graph[p]) {
            if (v != root) {
                res += dfs(v, p, (curr + cost) % signalSpeed);
            }
        }
        return res;
    };

    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        int pre = 0;
        for (auto &[v, cost] : graph[i]) {
            int cnt = dfs(v, i, cost % signalSpeed);
            res[i] += pre * cnt;
            pre += cnt;
        }
    }
    return res;
}
