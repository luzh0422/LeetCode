//
// Created by luzh on 2022/2/12.
//

#include "Solution1020.h"
#include <queue>

int Solution1020::numEnclaves(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> visit(m, vector<int>(n, 0));
    vector<int> dirs = {-1, 0, 1, 0, -1};
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int curr = 0;
            if (grid[i][j] == 1 && visit[i][j] == 0) {
                queue<pair<int, int>> q = {};
                q.push({i, j});
                visit[i][j] = 1;
                bool cross = false;
                while (!q.empty()) {
                    auto currPos = q.front();
                    q.pop();
                    int x = currPos.first;
                    int y = currPos.second;
                    curr++;
                    for (int i = 0; i < 4; i++) {
                        int tempX = x + dirs[i];
                        int tempY = y + dirs[i + 1];
                        if (tempX < 0 || tempX >= m || tempY < 0 || tempY >= n) {
                            cross = true;
                        } else if (grid[tempX][tempY] == 1 && visit[tempX][tempY] == 0) {
                            q.push({tempX, tempY});
                            visit[tempX][tempY] = 1;
                        }
                    }
                }
                if (cross) {
                    curr = 0;
                }
            }
            ans += curr;
        }
    }
    return ans;
}
