//
// Created by luzh on 2022/1/11.
//

#include "Solution1036.h"
#include <unordered_set>
#include <queue>

/**
 * 给n个顶点，如何能围城最大面积？
 * 应当尽可能利用边界作为围城图形的某些边；
 * 即，利用两个边界作为直角边，n个顶点作为斜边围城的图形面积最大。
 * 面积为（0 + 1 + 2 ... + n - 1) = n * (n - 1) / 2;
 */

int EDGE = (int)1e6, MAX = (int)1e5;
long long BASE  = 13331; // 一个通用hash算法值，此处使用是由于没有column值；
unordered_set<long long> set;
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

bool Solution1036::isEscapePossible(vector<vector<int>> &blocked, vector<int> &source, vector<int> &target) {
    for (auto& p : blocked) {
        set.insert(p[0] * BASE + p[1]);
    }
    int n = blocked.size();
    MAX = n * (n - 1) / 2;
    return check(source, target) && check(target, source);
}

bool Solution1036::check(vector<int>& a, vector<int>& b) {
    unordered_set<long long> vis;
    queue<pair<int, int>> q;
    q.push( {a[0], a[1]} );
    vis.insert(a[0] * BASE + a[1]);
    while (!q.empty() && vis.size() <= MAX) {
        auto t = q.front();
        q.pop();
        int x = t.first, y = t.second;
        if (x == b[0] && y == b[1]) {
            return true;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (nx < 0 || nx >= EDGE || ny < 0 || ny >= EDGE)
                continue;
            if (set.count(nx * BASE + ny))
                continue;
            if (vis.count(nx * BASE + ny))
                continue;
            q.push( {nx, ny } );
            vis.insert(nx * BASE + ny);
        }
    }
    return vis.size() > MAX;
}
