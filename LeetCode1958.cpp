//
// Created by luzehui on 2024/7/7.
//

#include "LeetCode1958.h"

bool LeetCode1958::checkMove(vector<vector<char>> &board, int rMove, int cMove, char color) {
    const vector<vector<int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
    bool res = false;
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < 8; i++) {
        auto direction = directions[i];
        int rowStep = direction[0], colStep = direction[1], distance = 1;
        int nextRow = rMove + rowStep, nextCol = cMove + colStep;
        while (nextRow >= 0 && nextRow < m && nextCol >= 0 && nextCol < n && board[nextRow][nextCol] != color && board[nextRow][nextCol] != '.') {
            distance++;
            nextRow += rowStep;
            nextCol += colStep;
        }
        if (nextRow >= 0 && nextRow < m && nextCol >= 0 && nextCol < n && board[nextRow][nextCol] == color && distance > 1) {
            res = true;
            break;
        }
    }
    return res;
}
