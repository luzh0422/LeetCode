//
// Created by luzehui on 24-12-6.
//

#include "LeetCode999.h"

int LeetCode999::numRookCaptures(vector<vector<char>> &board) {
    int row = 0, col = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 'R') {
                row = i;
                col = j;
                break;
            }
        }
    }
    int step = 1, res = 0;
    while (row - step >= 0) {
        if (board[row - step][col] == 'p') {
            res++;
            break;
        }
        if (board[row - step][col] == 'B') {
            break;
        }
        step++;
    }
    step = 1;
    while (row + step < 8) {
        if (board[row + step][col] == 'p') {
            res++;
            break;
        }
        if (board[row + step][col] == 'B') {
            break;
        }
        step++;
    }
    step = 1;
    while (col - step >= 0) {
        if (board[row][col - step] == 'p') {
            res++;
            break;
        }
        if (board[row][col - step] == 'B') {
            break;
        }
        step++;
    }
    step = 1;
    while (col + step < 8) {
        if (board[row][col + step] == 'p') {
            res++;
            break;
        }
        if (board[row][col + step] == 'B') {
            break;
        }
        step++;
    }
    return res;
}
