//
// Created by 陆泽辉 on 2023/6/29.
//

#include "LeetCode1253.h"

vector<vector<int>> LeetCode1253::reconstructMatrix(int upper, int lower, vector<int> &colsum) {
    int n = colsum.size();
    vector<vector<int>> arr(2, vector<int>(n, 0));
    int upTemp = 0,  lowTemp = 0;
    for (int i = 0; i < n; i++) {
        if (colsum[i] == 2) {
            arr[0][i] = 1;
            arr[1][i] = 1;
            upTemp++;
            lowTemp++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (colsum[i] == 1) {
            if (upTemp < upper) {
                arr[0][i] = 1;
                upTemp++;
            } else if (lowTemp < lower) {
                arr[1][i] = 1;
                lowTemp++;
            } else {
                return {};
            }
        }
    }
    if (upTemp == upper && lowTemp == lower) {
        return arr;
    }
    return {};
}
