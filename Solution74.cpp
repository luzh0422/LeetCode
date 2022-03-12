//
// Created by luzh on 2021/3/30.
//

#include "Solution74.h"

bool Solution74::searchMatrix(vector<vector<int>> &matrix, int target) {
    int row = matrix.size();
    int column = matrix[0].size();
    int searchRow = 0;
    for (int i = 0; i < row; i++) {
        if (matrix[i][column - 1] >= target) {
            searchRow = i;
            break;
        }
    }
    int start = 0, end = column - 1, middle = (start + end) / 2;
    while (start <= end) {
        if (matrix[searchRow][middle] == target) {
            return true;
        } else if (matrix[searchRow][middle] > target) {
            end = middle - 1;
            middle = (start + end) / 2;
        } else {
            start = middle + 1;
            middle = (start + end) / 2;
        }
    }
    return false;
}
