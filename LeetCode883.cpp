//
// Created by 陆泽辉 on 2022/4/26.
//

#include "LeetCode883.h"

int LeetCode883::projectionArea(vector<vector<int>> &grid) {
    int ret = 0;
    int row = grid.size();
    int column = grid[0].size();
    /**
     * 俯视图；
     */
    for (int i = 0; i < row; i++) {
        int length = 0;
        for (int j = 0; j < column; j++) {
            if (grid[i][j] != 0) {
                length++;
            }
        }
        ret += length;
    }
    /**
     * 前视图；
     */
     for (int j = 0; j < column; j++) {
         int length = 0;
         for (int i = 0; i < row; i++) {
            length = max(length, grid[i][j]);
         }
         ret += length;
     }
     /**
      * 左视图；
      */
     for (int i = 0; i < row; i++) {
         int length = 0;
         for (int j = 0; j < column; j++) {
             length = max(length, grid[i][j]);
         }
         ret += length;
     }
     return ret;
}
