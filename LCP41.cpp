//
// Created by 陆泽辉 on 2023/6/21.
//

#include "LCP41.h"
#include <queue>
namespace {
    const int dirs[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
}

int LCP41::flipChess(vector<string> &chessboard) {
   int res = 0, m = chessboard.size(), n = chessboard[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (chessboard[i][j] == '.') {
                res = max(res, bfs(chessboard, i, j));
            }
        }
    }
    return res;
}

int LCP41::bfs(vector<string> chessboard, int px, int py) {
    int cnt = 0;
    queue<pair<int, int>> q;
    q.emplace(px, py);
    chessboard[px][py] = 'X';
    while (!q.empty()) {
        pair<int, int> t = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            if (judge(chessboard, t.first, t.second, dirs[i][0], dirs[i][1])) {
                int x = t.first + dirs[i][0], y = t.second + dirs[i][1];
                while (chessboard[x][y] != 'X') {
                    q.emplace(x, y);
                    chessboard[x][y] = 'X';
                    x += dirs[i][0];
                    y += dirs[i][1];
                    ++cnt;
                }
            }
        }
    }
    return cnt;
}

bool LCP41::judge(const vector<string> &chessboard, int x, int y, int dx, int dy) {
    x += dx;
    y += dy;
    int m = chessboard.size(), n = chessboard[0].size();
    while (0 <= x && x < m && 0 <= y && y < n) {
        if (chessboard[x][y] == 'X') {
            return true;
        } else if (chessboard[x][y] == '.') {
            return false;
        }
        x += dx;
        y += dy;
    }
    return false;
}
