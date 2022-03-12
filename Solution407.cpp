//
// Created by luzh on 2021/11/3.
//

#include "Solution407.h"
#include <queue>

typedef pair<int, int> pii;

int Solution407::trapRainWater(vector<vector<int>> &heightMap) {
    if (heightMap.size() <= 2 || heightMap[0].size() <= 2) {
        return 0;
    }
    int m = heightMap.size();
    int n = heightMap[0].size();
    /**
     * 创建最小堆；
     */
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<vector<bool>> visit(m, vector<bool>(n, false));

    /**
     * 初始化，矩阵的边缘无法盛水，所以盛水后的高度就是原始高度；
     */
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                pq.push({heightMap[i][j], i * n + j}); // i * n + j 代表元素的位置；
                visit[i][j] = true;
            }
        }
    }

    int res = 0;
    /**
     * 用dirs找到元素四周的元素，heightMap[x - 1][y], heightMap[x][y + 1], heightMap[x + 1][y], heightMap[x][y - 1];
     */
    vector<int> dirs = {-1, 0, 1, 0, -1};
    while (!pq.empty()) {
        pii curr = pq.top();
        pq.pop();
        for (int k = 0; k < 4; ++k) {
            /**
             * 获取横、纵坐标；
             */
            int nx = curr.second / n + dirs[k];
            int ny = curr.second % n + dirs[k + 1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visit[nx][ny]) {
                if (heightMap[nx][ny] < curr.first) {
                    res += curr.first - heightMap[nx][ny];
                }
                visit[nx][ny] = true;
                pq.push({max(heightMap[nx][ny], curr.first), nx * n + ny});
            }
        }
    }
    return res;
}
