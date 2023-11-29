//
// Created by 陆泽辉 on 2022/10/26.
//

#include "LeetCode934.h"
#include <queue>
namespace {
    vector<int> dirs = {-1, 0, 1, 0, -1};
}

int LeetCode934::shortestBridge(vector<vector<int>> &grid) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> island;
    constrctIsland(grid, island);
    int n = grid.size();
    for (int i = 0; i < island.size(); i++) {
        q.emplace(island[i]);
    }
    int step = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            /**
             * q.front取值不可以使用引用，避免在pop后，内存被销毁；
             */
            auto curr = q.front();
            q.pop();
            auto currX = curr.first;
            auto currY = curr.second;
            for (int j = 0; j < 4; j++) {
                int nextX = currX + dirs[j];
                int nextY = currY + dirs[j + 1];
                if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n) {
                    if (grid[nextX][nextY] == 0) {
                        /**
                         * 要在放到队列的时候进行标记，以防被重复放入队列；
                         */
                        grid[nextX][nextY] = -1;
                        q.emplace(nextX, nextY);
                    } else if (grid[nextX][nextY] == 1) {
                        return step;
                    }
                }
            }
        }
        step++;
    }
    return step;
}

void LeetCode934::constrctIsland(vector<vector<int>> &grid, vector<pair<int, int>> &island) {
    queue<pair<int, int>> q;
    int n = grid.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                grid[i][j] = -1;
                q.emplace(i, j);
                while (!q.empty()) {
                    auto& curr = q.front();
                    q.pop();
                    int currX = curr.first;
                    int currY = curr.second;
                    /**
                     * 要在放到队列的时候进行标记，以防被重复放入队列；
                     */
                    grid[currX][currY] = -1;
                    island.emplace_back(currX, currY);
                    for (int i = 0; i < 4; i++) {
                        int nextX = currX + dirs[i];
                        int nextY = currY + dirs[i + 1];
                        if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n && grid[nextX][nextY] == 1) {
                            /**
                             * 要在放到队列的时候进行标记，以防被重复放入队列；
                             */
                            grid[nextX][nextY] = -1;
                            q.emplace(nextX, nextY);
                        }
                    }
                }
                return;
            }
        }
    }
    return;
}
