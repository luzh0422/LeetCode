//
// Created by 陆泽辉 on 2022/9/4.
//

#include "LeetCode1582.h"

int LeetCode1582::numSpecial(vector<vector<int>> &mat) {
    int ret = 0;
    int row = mat.size(), col = mat[0].size();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (mat[i][j] == 1) {
                bool tag = true;
                for (int k = 0; k < row; k++) {
                    if (i != k && mat[k][j] == 1) {
                        tag = false;
                        break;
                    }
                }
                if (tag) {
                    for (int k = 0; k < col; k++) {
                        if (j != k && mat[i][k] == 1) {
                            tag = false;
                        }
                    }
                }
                if (tag) {
                    ret++;
                }
                break;
            }
        }
    }
    return ret;
}
