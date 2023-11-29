//
// Created by 陆泽辉 on 2023/5/5.
//

#include "LeetCode2432.h"

int LeetCode2432::hardestWorker(int n, vector<vector<int>> &logs) {
    int curr = 0;
    int maxTime = 0;
    int res = -1;
    for (int i = 0; i < logs.size(); i++) {
        int id = logs[i][0];
        int time = logs[i][1];
        int delta = time - curr;
        if (delta > maxTime) {
            res = id;
            maxTime = delta;
        } else if (delta == maxTime && res > id) {
            res = id;
        }
        curr = time;
    }
    return res;
}
