//
// Created by 陆泽辉 on 2022/7/12.
//

#include "LeetCode1252.h"

int LeetCode1252::oddCells(int m, int n, vector<vector<int>> &indices) {
    vector<vector<bool>> odds(m, vector<bool>(n, false));
    int ret = 0;
    for (auto indice: indices) {
        int row = indice[0], column = indice[1];
        for (int i = 0; i < m; i++) {
            odds[i][column] = !odds[i][column];
            if (odds[i][column]) {
                ret++;
            } else {
                ret--;
            }
        }
        for (int i = 0; i < n; i++) {
            odds[row][i] = !odds[row][i];
            if (odds[i][column]) {
                ret++;
            } else {
                ret--;
            }
        }
    }
    return ret;
}
