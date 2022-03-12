//
// Created by luzh on 2022/2/18.
//

#include "Solution1791.h"

int Solution1791::findCenter(vector<vector<int>> &edges) {
    int n = edges.size();
    vector<int> indegree(n + 2, 0);
    for (int i = 0; i < n; i++) {
        indegree[edges[i][0]] ++;
        indegree[edges[i][1]] ++;
    }
    for (int i = 1; i < n + 2; i++) {
        if (indegree[i] == n) {
            return i;
        }
    }
    return -1;
}
