//
// Created by luzehui on 2024/9/21.
//

#include "LeetCode2374.h"

int LeetCode2374::edgeScore(vector<int> &edges) {
    int n = edges.size(), res = 0, index = 0;
    vector<int> records(n, 0);
    for (int i = 0; i < n; i++) {
        int curr = records[edges[i]] + i;
        records[edges[i]] = curr;
        if (curr > res) {
            res = curr;
            index = edges[i];
        } else if (curr == res && edges[i] < index) {
            index = edges[i];
        }
    }
    return index;
}
