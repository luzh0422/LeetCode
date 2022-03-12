//
// Created by luzh on 2021/9/17.
//

#include "Solution36.h"

bool Solution36::isValidSudoku(vector<vector<char>> &board) {
    int tag = 0;
    /**
     * 按行判断；
     */
    for (int i = 0; i < 9; i++) {
        tag = 0;
        for (int j = 0; j < 9; j++) {
            char c = board[i][j];
            if (c != '.') {
                int num = 1 << getNumByChar(c);
                if ((tag & num) != 0) {
                    return false;
                }
                tag ^= num;
            }
        }
    }
    /**
     * 按列判断；
     */
    for (int j = 0; j < 9; j++) {
        tag = 0;
        for (int i = 0; i < 9; i++) {
            char c = board[i][j];
            if (c != '.') {
                int num = 1 << getNumByChar(c);
                if ((tag & num) != 0) {
                    return false;
                }
                tag ^= num;
            }
        }
    }
    /**
     * 按九宫格判断；
     */
    for (int row = 0; row < 9; row += 3) {
        for (int column = 0; column < 9; column += 3) {
            if (!isValidSudoku(board, row, column)) {
                return false;
            }
        }
    }
    return true;
}

bool Solution36::isValidSudoku(vector<vector<char>> &board, int row, int column) {
    int tag = 0;
    for (int rowStep = 0; rowStep < 3; rowStep++) {
        for(int columnStep = 0; columnStep < 3; columnStep++) {
            char c = board[row + rowStep][column + columnStep];
            if (c != '.') {
                int num = 1 << getNumByChar(c);
                if ((tag & num) != 0) {
                    return false;
                }
                tag ^= num;
            }
        }
    }
    return true;
}

int Solution36::getNumByChar(char c) {
    return c - '0';
}
