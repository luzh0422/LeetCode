//
// Created by 陆泽辉 on 2022/5/23.
//

#include "LeetCode675.h"
#include <queue>

/**
 * 忽略了题干中的树木只能从低到高进行砍伐；
 * 我这种解法，是从起点开始砍伐，遇到高的树就砍不动了；
 * 而题目中只要是非0的节点都可以通过，但是要先砍伐低的树木，再砍伐高的树木；
 * @param forest
 * @return
 */

//int LeetCode675::cutOffTree(vector<vector<int>> &forest) {
//    int m = forest.size(), n = forest[0].size();
//    vector<vector<int>> visits(m, vector<int>(n, 0));
//    int ret = cutOffTree(forest, 0, visits, m, n);
//    for (int i = 0; i < m; ++i) {
//        for (int j = 0; j < n; ++j) {
//            if (forest[i][j] > 1 && visits[i][j] == 0) {
//                return -1;
//            }
//        }
//    }
//    return ret;
//}
//
//int LeetCode675::cutOffTree(vector<vector<int>> &forest, int curr, vector<vector<int>> &visits, int m, int n) {
//    int currRow = curr / n;
//    int currColumn = curr % n;
//    visits[currRow][currColumn] = 1;
//    const vector<int> dirs = {-1, 0, 1, 0, -1};
//    vector<int> roads = {};
//    for (int i = 0; i < 4; ++i) {
//        int nextRow = currRow + dirs[i];
//        int nextColumn = currColumn + dirs[i + 1];
//        if (nextRow >= 0 && nextRow < m && nextColumn >= 0 && nextColumn < n && visits[nextRow][nextColumn] == 0 && forest[nextRow][nextColumn] > forest[currRow][currColumn]) {
//            roads.push_back(cutOffTree(forest, nextRow * n + nextColumn, visits, m, n));
//        }
//    }
//    std::sort(roads.begin(), roads.end());
//    int ret = 1;
//    int roadsN = roads.size();
//    for (int i = 0; i < roadsN; i++) {
//        if (i != roadsN - 1) {
//            ret += 2 * roads[i];
//        } else {
//            ret += roads[i];
//        }
//    }
//    return ret;
//}

int LeetCode675::cutOffTree(vector<vector<int>> &forest) {
    int m = forest.size();
    int n = forest[0].size();
    int forestNum = 0;
    vector<pair<int, int>> forestCache;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (forest[i][j] > 1) {
                forestCache.emplace_back(forest[i][j], i * n + j);
                forestNum++;
            }
        }
    }
    sort(forestCache.begin(), forestCache.end(), [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
        return a.first < b.first;
    });
    int distance = 0;
    for (int i = 0; i < forestNum; i++) {
        int temp = -1;
        if (i == 0) {
            temp = bfs(forest, 0, forestCache[i].second, m, n);
        } else {
            temp = bfs(forest, forestCache[i - 1].second, forestCache[i].second, m, n);
        }
        if (temp == -1) {
            return -1;
        }
        distance += temp;
    }
    return distance;
}

/**
 * 利用bfs求无权图的最短距离，有3点需要注意：
 * 1. 访问过的节点记录要在节点加入queue的时机，而不是访问节点的时机，避免节点的重复加入queue；
 * 2. 利用vector<pair<int, int>>数据结构，分别记录节点的位置，和节点的距离；
 * 3. 利用vector<int> dirs = {-1, 0, 1, 0, -1}来管理节点向上、下、左、右四个方向的移动；
 * @param forest
 * @param start
 * @param end
 * @param m
 * @param n
 * @return
 */
int LeetCode675::bfs(vector<vector<int>> &forest, int start, int end, int m, int n)  {
    vector<vector<int>> visit(m, vector<int>(n, 0));
    queue<pair<int, int>> q;
    q.emplace(start, 0);
    const vector<int> dirs = {-1, 0, 1, 0, -1};
    while (!q.empty()) {
        auto curr = q.front().first;
        int currDistance = q.front().second;
        q.pop();
        if (curr == end) {
            return currDistance;
        }
        int currRow = curr / n;
        int currCol = curr % n;
        /**
         * 这个是为了记录初始化的节点；
         */
        visit[currRow][currCol] = 1;
        for (int i = 0; i < 4; ++i) {
            int nextRow = currRow + dirs[i];
            int nextCol = currCol + dirs[i + 1];
            if (nextRow >= 0 && nextRow < m && nextCol >= 0 && nextCol < n && visit[nextRow][nextCol] == 0 && forest[nextRow][nextCol] >= 1) {
                /**
                 * BFS的访问节点的记录，一定要在节点入队的时候进行记录，要不会造成冗余计算；
                 */
                visit[nextRow][nextCol] = 1;
                q.emplace(nextRow * n + nextCol, currDistance + 1);
            }
        }
    }
    return -1;
}
