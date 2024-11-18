//
// Created by luzehui on 2024/7/23.
//

#include "LeetCode2850.h"
#include <functional>
#include <queue>

int LeetCode2850::minimumMoves(vector<vector<int>> &grid) {
//    const int n = 3;
//    typedef int F_BFS (vector<vector<int>>&, int, int);
//    function<int(vector<vector<int>>&, int, int)> bfs = [&](vector<vector<int>>& visits, int row, int col) -> int {
//        vector<vector<int>> directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
//        queue<tuple<int, int, int>> q;
//        visits[row][col] = 1;
//        q.push({row, col, 0});
//        while (!q.empty()) {
//            auto node = q.front();
//            q.pop();
//            int currRow = std::get<0>(node);
//            int currCol = std::get<1>(node);
//            int dis = std::get<2>(node);
//            if (grid[currRow][currCol] > 1) {
//                grid[currRow][currCol]--;
//                return dis;
//            }
//            for (int i = 0; i < 4; i++) {
//                int nextRow = currRow + directions[i][0];
//                int nextCol = currCol + directions[i][1];
//                if (nextRow >= 0 && nextRow < 3 && nextCol >= 0 && nextCol < 3 && visits[nextRow][nextCol] == 0) {
//                    visits[nextRow][nextCol] = 1;
//                    q.push({nextRow, nextCol, dis + 1});
//                }
//            }
//        }
//        return -1;
//    };
//    int res = 0;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            if (grid[i][j] == 0) {
//                vector<vector<int>> visits(3, vector<int>(3, 0));
//                res += bfs(visits, i, j);
//            }
//        }
//    }
//    return res;
    vector<pair<int, int>> more, less;
    for (int i = 2; i >= 0; i--) {
        for (int j = 2; j >= 0; j--) {
            if (grid[i][j] > 1) {
                for (int k = 1; k < grid[i][j]; k++) {
                    more.push_back({i, j});
                }
            } else if (grid[i][j] == 0) {
                less.push_back({i, j});
            }
        }
    }
    int res = INT_MAX;
    do {
        int steps = 0;
        for (int i = 0; i < more.size(); ++i) {
            steps += abs(more[i].first - less[i].first) +
                     abs(more[i].second - less[i].second);
        }
        res = min(res, steps);
    } while (prev_permutation(more.begin(), more.end()));
    return res;
}
