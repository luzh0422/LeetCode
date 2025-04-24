//
// Created by luzehui on 2024/11/23.
//

#include "LeetCode3238.h"

int LeetCode3238::winningPlayerCount(int n, vector<vector<int>> &pick) {
    vector<vector<int>> playerCount(n, vector<int>(101, 0));
    vector<bool> playerTag(n, false);
    int res = 0;
    for (auto &p : pick) {
        if (++playerCount[p[0]][p[1]] > p[0] && !playerTag[p[0]]) {
            playerTag[p[0]] = true;
            res++;
        }
    }
    return res;
}
