//
// Created by luzehui on 2024/5/14.
//

#include "LeetCode2244.h"

int LeetCode2244::minimumRounds(vector<int> &tasks) {
    std::sort(tasks.begin(), tasks.end());
    int res = 0, count = 0, currTask = tasks[0];
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i] == currTask) {
            count++;
        } else {
            if (count == 1)
                return -1;
            res += (count + 2) / 3;
            currTask = tasks[i];
            count = 1;
        }
    }
    if (count != 0) {
        if (count == 1)
            return -1;
        res += (count + 2) / 3;
    }
    return res;
}
