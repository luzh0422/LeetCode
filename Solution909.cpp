//
// Created by luzh on 2021/6/27.
//

#include "Solution909.h"

#include <queue>

int Solution909::snakesAndLadders(vector<vector<int>> &board) {
    int n = board.size();
    vector<int> vis(n * n + 1);
    queue<pair<int, int>> q;
    /**
     * 处于顶点1，步数为0；
     */
    q.emplace(1, 0);
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        for (int i = 1; i <= 6; i++) {
            int nxt = p.first + i;
            if (nxt > n * n) { // 超出边界；
                break;
            }
            auto rc = id2rc(nxt, n); // 得到下一步的行列；
            if (board[rc.first][rc.second] > 0) { // 存在蛇或梯子；
                nxt = board[rc.first][rc.second];
            }
            if (nxt = n * n) { // 到达终点；
                return p.second + 1;
            }
            if (!vis[nxt]) {
                vis[nxt] = true;
                q.emplace(nxt, p.second + 1);
            }
        }
    }
    return -1;
}

pair<int, int> Solution909::id2rc(int id, int n) {
    int r = (id - 1) / n;
    int c = (id - 1) % n;
    if (r % 2 == 1) { // 根据当前行是奇数行还是偶数判断列数是从左往右还是从右往左；
        c = n - 1 - c;
    }
    return {n - 1 - r, c};
}


