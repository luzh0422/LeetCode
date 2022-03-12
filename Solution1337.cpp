//
// Created by luzh on 2021/8/1.
//

#include "Solution1337.h"

vector<int> Solution1337::kWeakestRows(vector<vector<int>> &mat, int k) {
    int row = mat.size();
    int column = mat[0].size();
    vector<vector<int>> count(column + 1, vector<int>());
    for (int i = 0; i < row; i++) {
        int num = 0;
        for (int j = 0; j < column; j++) {
            if (mat[i][j] == 0) {
                break;
            }
            num++;
        }
        count[num].push_back(i);
    }
    int index = 0;
    vector<int> ret = {};
    for (int i = 0; i < column; i++) {
        for (int j = 0; j < count[i].size(); j++) {
            ret.push_back(count[i][j]);
            index++;
            if (index >= k) {
                break;
            }
        }
        if (index >= k) {
            break;
        }
    }
    return ret;
}
