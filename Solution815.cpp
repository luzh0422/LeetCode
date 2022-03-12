//
// Created by luzh on 2021/6/28.
//

#include "Solution815.h"

#include <unordered_map>
#include <queue>

/**
 * 因为求解的是要更换多少条公交路线，因为要把每一条公交路线作为一个节点；
 * @param routes
 * @param source
 * @param target
 * @return
 */
int Solution815::numBusesToDestination(vector<vector<int>> &routes, int source, int target) {
    if (source == target) {
        return 0;
    }
    int n = routes.size();
    /**
     * 邻接矩阵构建图；
     */
    vector<vector<int>> edge(n, vector<int>(n));
    /**
     * 每个站点对应的路线；
     */
    unordered_map<int, vector<int>> rec;
    /**
     * 将路线构建图；
     */
    for (int i = 0; i < n; i++) {
        for (auto& site: routes[i]) {
            for (auto& j: rec[site]) {
                edge[i][j] = edge[j][i] = true;
            }
            rec[site].push_back(i);
        }
    }
    /**
     * dis用于判断路线是否被访问过；由于是广度优先算法，因此如果路线被访问过，后面的访问数值一定更大；
     */
    vector<int> dis(n, -1);
    /**
     * 利用队列实现广度优先搜索；
     */
    queue<int> que;
    /**
     * 将起点对应的每一条路线加入队列；
     */
    for (auto& site: rec[source]) {
        dis[site] = 1;
        que.push(site);
    }
    /**
     * 广度优先算法求最短路径；
     */
    while (!que.empty()) {
        int x = que.front();
        que.pop();
        for (int y = 0; y < n; y++) {
            if (edge[x][y] && dis[y] == -1) {
                dis[y] = dis[x] + 1;
                que.push(y);
            }
        }
    }
    int ret = INT_MAX;
    for (auto& site: rec[target]) {
        if (dis[site] != -1) {
            ret = min(ret, dis[site]);
        }
    }
    return ret == INT_MAX ? -1 : ret;
}
