//
// Created by luzehui on 2024/9/17.
//

#include "LeetCode1450.h"

int LeetCode1450::busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime) {
    int res = 0;
    for (int i = 0; i < startTime.size(); i++) {
        if (queryTime >= startTime[i] && queryTime <= endTime[i]) {
            res++;
        }
    }
    return res;
}
