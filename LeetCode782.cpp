//
// Created by 陆泽辉 on 2022/8/23.
//

#include "LeetCode782.h"

int LeetCode782::movesToChessboard(vector<vector<int>> &board) {
    int n = board.size();
    int rowMask = 0, colMask = 0;
    /**
     * 检查棋盘的第一行与第一列；
     */
    for (int i = 0; i < n; i++) {
        rowMask |= (board[0][i] << i);
        colMask |= (board[i][0] << i);
    }
    int reverseRowMask = ((1 << n) - 1) ^ rowMask;
    int reverseColMask = ((1 << n) - 1) ^ colMask;
    int rowCnt = 0, colCnt = 0;
    for (int i = 0; i < n; i++) {
        int currRowMask = 0;
        int currColMask = 0;
        for (int j = 0; j < n; j++) {
            currRowMask |= (board[i][j] << j);
            currColMask |= (board[j][i] << j);
        }
        if (currRowMask != rowMask && currRowMask != reverseRowMask) {
            return -1;
        } else if (currRowMask == rowMask) {
            rowCnt++;
        }
        if (currColMask != colMask && currColMask != reverseColMask) {
            return -1;
        } else if (currColMask == colMask) {
            colCnt++;
        }
    }
    int rowMoves = getMoves(rowMask, rowCnt, n);
    int colMoves = getMoves(colMask, colCnt, n);
    return (rowMoves == -1 || colMoves == -1) ? -1 : (rowMoves + colMoves);
}

int LeetCode782::getMoves(int mask, int count, int n) {
    /**
     * 计算mask的二进制中有多少个1；
     */
    int ones = __builtin_popcount(mask);
    if (n & 1) {
        /**
         * 如果n为奇数，则每一行中1 与 0的数目相差为1，且满足相邻行交替；
         */
        if (abs(n - 2 * ones) != 1 || abs(n - 2 * count) != 1) {
            return -1;
        }
        if (ones == (n >> 1)) {
            /**
             * 如果 1 的个数少，则 1 的站位一定是偶数位；
             * 偶数位变为1的最小交换次数；
             */
            return n / 2 - __builtin_popcount(mask & 0xAAAAAAAA);
        } else {
            /**
             * 如果 1 的个数多，则 1 的站位一定是奇数位；
             * 奇数位变为1的最小交换次数；
             */
            return (n + 1) / 2 - __builtin_popcount(mask & 0x55555555);
        }
    } else {
        if (ones != (n >> 1) || count != (n >> 1)) {
            return -1;
        }
        /**
         * 偶数位都变为1需要的交换次数；
         */
        int count0 = n / 2 - __builtin_popcount(mask & 0xAAAAAAAA);
        /**
         * 奇数位都变为1需要的交换次数；
         */
        int count1 = n / 2 - __builtin_popcount(mask & 0x55555555);
        return min(count0, count1);
    }
}
