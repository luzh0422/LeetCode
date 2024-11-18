//
// Created by luzehui on 2024/9/22.
//

#include "LeetCode997.h"

int LeetCode997::findJudge(int n, vector<vector<int>> &trust) {
    vector<int> indegrees(n, 0);
    vector<int> outdegrees(n, 0);
    for (int i = 0; i < trust.size(); i++) {
        int a = trust[i][0], b = trust[i][1];
        indegrees[b - 1]++;
        outdegrees[a - 1]++;
    }
    int res = -1;
    for (int i = 0; i < n; i++) {
        if (indegrees[i] == n - 1 && outdegrees[i] == 0) {
            res = i + 1;
            break;
        }
    }
    return res;
}
