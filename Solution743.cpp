//
// Created by luzh on 2021/8/2.
//

#include "Solution743.h"

int Solution743::networkDelayTime(vector<vector<int>> &times, int n, int k) {
    const int inf = INT_MAX / 2;
    /**
     * 初始化图；
     */
    vector<vector<int>> g(n, vector<int>(n, inf));
    for (auto &time : times) {
        int x = time[0] - 1;
        int y = time[1] - 1;
        g[x][y] = time[2];
    }
    /**
     * 初始化每个节点的距离；
     */
    vector<int> dist(n, inf);
    dist[k - 1] = 0;
    vector<int> visit(n);
    for (int i = 0; i < n; ++i) {
        int node = -1;
        /**
         * 找到距离开始节点最近的节点；
         */
        for (int j = 0; j < n; j++) {
            if (!visit[j] && (node == -1 || dist[j] < dist[node])) {
                node = j;
            }
        }
        visit[node] = true;
        /**
         * 根据最近节点，对其他节点进行松弛；
         */
        for (int j = 0; j < n; j++) {
            dist[j] = min(dist[j], dist[node] + g[node][j]);
        }
    }
    int ans = *max_element(dist.begin(), dist.end());
    return ans == inf ? -1 : ans;
}
