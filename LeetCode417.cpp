//
// Created by 陆泽辉 on 2022/4/27.
//

#include "LeetCode417.h"

const vector<int> dirs = {-1, 0, 1, 0, -1};

//vector<vector<int>> LeetCode417::pacificAtlantic(vector<vector<int>> &heights) {
//    int m = heights.size();
//    int n = heights[0].size();
//    vector<vector<int>> pacificOceans(m, vector<int>(n, -1));
//    vector<vector<int>> atlanticOceans(m, vector<int>(n, -1));
//    vector<vector<int>> ret;
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            vector<vector<int>> visits1(m, vector<int>(n, 0));
//            if (pacificOceans[i][j] == 1 || dfs({i, j}, {0, 0}, heights, visits1, pacificOceans, m, n)) {
//                vector<vector<int>> visits2(m, vector<int>(n, 0));
//                if (dfs({i, j}, {m - 1, n - 1}, heights, visits2, atlanticOceans, m, n)) {
//                    ret.emplace_back(i, j);
//                }
//            }
//        }
//    }
//    return ret;
//}
//
//bool LeetCode417::dfs(pair<int, int> currPos, pair<int, int> target, vector<vector<int>> &heights, vector<vector<int>> &visits, vector<vector<int>> &oceans, int m, int n) {
//    int currPosX = currPos.first, currPosY = currPos.second;
//    if (currPosX == target.first || currPosY == target.second || oceans[currPosX][currPosY] == 1) {
//        oceans[currPosX][currPosY] = 1;
//        return true;
//    }
//    visits[currPosX][currPosY] = 1;
//    for (int i = 0; i < 4; i++) {
//        int nextX = currPosX + dirs[i], nextY = currPosY + dirs[i + 1];
//        if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n && visits[nextX][nextY] == 0 && heights[currPosX][currPosY] >= heights[nextX][nextY]) {
//            if (dfs({nextX, nextY}, target, heights, visits, oceans, m, n)) {
//                oceans[currPosX][currPosY] = 1;
//                return true;
//            }
//        }
//    }
//    return false;
//}

vector<vector<int>> LeetCode417::pacificAtlantic(vector<vector<int>> &heights) {
    int m = heights.size();
    int n = heights[0].size();
    vector<vector<int>> pacificOceans(m, vector<int>(n, 0));
    vector<vector<int>> atlanticOceans(m, vector<int>(n, 0));
    vector<vector<int>> ret;
    for (int i = 0; i < n; i++) {
        dfs({0, i}, heights, pacificOceans, m, n);
        dfs({m - 1, i}, heights, atlanticOceans, m, n);
    }
    for (int i = 0; i < m; i++) {
        dfs({i, 0}, heights, pacificOceans, m, n);
        dfs({i, n - 1}, heights, atlanticOceans, m, n);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (pacificOceans[i][j] && atlanticOceans[i][j]) {
                ret.push_back({i, j});
            }
        }
    }
    return ret;
}

void LeetCode417::dfs(pair<int, int> currPos, vector<vector<int>> &heights, vector<vector<int>> &oceans, int m, int n) {
    int currX = currPos.first, currY = currPos.second;
    oceans[currX][currY] = 1;
    for (int i = 0; i < 4; i++) {
        int nextX = currX + dirs[i];
        int nextY = currY + dirs[i + 1];
        if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n && heights[nextX][nextY] >= heights[currX][currY] && oceans[nextX][nextY] == 0) {
            dfs({nextX, nextY}, heights, oceans, m, n);
        }
    }
    return;
}
