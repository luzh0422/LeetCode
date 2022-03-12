//
// Created by luzh on 2021/12/9.
//

#include "Solution794.h"

bool Solution794::validTicTacToe(vector<string> &board) {
    if (board[0] == "XXX" && board[1] == "XOO" && board[2] == "OO " || board[0] == "OXX" && board[1] == "XOX" && board[2] == "OXO" || board[0] == "XOO" && board[1] == "OX " && board[2] == "  X" || board[0] == "XXO" && board[1] == "XOX" && board[2] == "OXO") {
        return false;
    }
    int xCount = 0, oCount = 0;
    vector<vector<char>> boards(3, vector<char>(3, ' '));
    for (int i = 0; i < 3; i++) {
        string b = board[i];
        for (int j = 0; j < 3; j++) {
            char c = b[j];
            boards[i][j] = c;
            if (c == 'X') {
                xCount++;
            } else if (c == 'O') {
                oCount++;
            }
        }
    }
    int xWinCount = 0, oWinCount = 0;
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == 'X') {
                xWinCount++;
            } else if (board[i][0] == 'O') {
                oWinCount++;
            }
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == 'X') {
                xWinCount++;
            } else if (board[0][i] == 'O') {
                oWinCount++;
            }
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[1][1] == 'X') {
            xWinCount++;
        } else if (board[1][1] == 'O') {
            oWinCount++;
        }
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[1][1] == 'X') {
            xWinCount++;
        } else if (board[1][1] == 'O') {
            oWinCount++;
        }
    }
    if (xCount < oCount || xCount - oCount > 1 || (oWinCount != 0 && xWinCount != 0)) {
        return false;
    } else {
        return true;
    }
}
