//
// Created by luzehui on 2024/6/11.
//

#include "LeetCode419.h"

int LeetCode419::countBattleships(vector<vector<char>> &board) {
    int m = board.size(), n = board[0].size();
    vector<vector<int>> visits(m, vector<int>(n, 0));
    int res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (visits[i][j] == 0 && board[i][j] == 'X') {
                int k = i;
                while (k < m && board[k][j] == 'X') {
                    visits[k][j] = 1;
                    k++;
                }
                k = j;
                while (k < n && board[i][k] == 'X') {
                    visits[i][k] = 1;
                    k++;
                }
                res++;
            }
        }
    }
    return res;
}
