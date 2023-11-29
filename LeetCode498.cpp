//
// Created by 陆泽辉 on 2022/6/14.
//

#include "LeetCode498.h"

/**
 * 找规律问题；
 * 我觉得亮点是使用x、y作为当前值；nx、ny作为下一个值；
 * @param mat
 * @return
 */
vector<int> LeetCode498::findDiagonalOrder(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size(), cnt = m * n;
    vector<int> ret(cnt);
    int x = 0, y = 0, dir = 1, idx = 0;
    while (idx < cnt) {
        ret[idx++] = mat[x][y];
        int nx = x, ny = y;
        /**
         * 右上角;
         */
        if (dir == 1) {
            nx = x - 1;
            ny = y + 1;
        } else {
            /**
             * 左下角;
             */
            nx = x + 1;
            ny = y - 1;
        }
        if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
            if (dir == 1) {
                nx = y + 1 < n ? x : x + 1;
                ny = y + 1 < n ? y + 1 : y;
            } else {
                nx = x + 1 < m ? x + 1 : x;
                ny = x + 1 < m ? y : y + 1;
            }
            dir *= -1;
        }
        x = nx;
        y = ny;
    }
    return ret;
}
