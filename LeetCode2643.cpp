//
// Created by luzehui on 25-3-22.
//

#include "LeetCode2643.h"

vector<int> LeetCode2643::rowAndMaximumOnes(vector<vector<int>> &mat) {
    int row = 0, oneCount = 0;
    for (int i = 0; i < mat.size(); i++) {
        int currOneCount = 0;
        for (int j = 0; j < mat[0].size(); j++) {
            currOneCount += mat[i][j];
        }
        if (currOneCount > oneCount) {
            oneCount = currOneCount;
            row = i;
        }
    }
    return {row, oneCount};
}
