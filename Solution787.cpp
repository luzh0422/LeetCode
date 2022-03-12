//
// Created by luzh on 2021/8/24.
//

#include "Solution787.h"

/**
 * Bellman-ford算法，遍历每一个节点，然后遍历每一条边，对每一个具有连通性的节点做松弛；
 * @param n
 * @param flights
 * @param src
 * @param dst
 * @param k
 * @return
 */
int Solution787::findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
    /**
     * 使得无穷大 + 无穷大 依然是无穷大；
     */
    const int INF = 0x3f3f3f3f;
    vector<int> dis(n, INF);
    dis[src] = 0;
    for (int i = 0; i < k + 1; i++) {
        /**
         * 确保每一轮只走一步；
         */
        vector<int> temp(dis);
        for (auto& flight : flights) {
            dis[flight[1]] = min(dis[flight[1]], temp[flight[0]] + flight[2]);
        }
    }
    if (dis[dst] >= INF) {
        return -1;
    }
    return dis[dst];
}
