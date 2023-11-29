//
// Created by 陆泽辉 on 2023/6/22.
//

#include "Mian1619.h"
#include <queue>

namespace {
    const int dirs[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
}

vector<int> Mian1619::pondSizes(vector<vector<int>> &land) {
    int m = land.size(), n = land[0].size();
    vector<int> res;
    vector<vector<int>> visits(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (visits[i][j] == 0 && land[i][j] == 0) {
                int ans = bfs(land, visits, i, j);
                res.push_back(ans);
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int Mian1619::bfs(vector<vector<int>> &land, vector<vector<int>> &visits, int currRow, int currCol) {
    visits[currRow][currCol] = 1;
    int m = land.size(), n = land[0].size();
    queue<pair<int, int>> q;
    q.emplace(currRow, currCol);
    int res = 1;
    while (!q.empty()) {
        pair<int, int> pos = q.front();
        q.pop();
        int row = pos.first, col = pos.second;
        for (int i = 0; i < 8; i++) {
            int nextRow = row + dirs[i][0];
            int nextCol = col + dirs[i][1];
            if (0 <= nextRow && nextRow < m && 0 <= nextCol && nextCol < n && visits[nextRow][nextCol] == 0 && land[nextRow][nextCol] == 0) {
                visits[nextRow][nextCol] = 1;
                res++;
                q.emplace(nextRow, nextCol);
            }
        }
    }
    return res;
}
