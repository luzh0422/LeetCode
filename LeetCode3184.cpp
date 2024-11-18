//
// Created by luzehui on 2024/10/22.
//

#include "LeetCode3184.h"

int LeetCode3184::countCompleteDayPairs(vector<int> &hours) {
    int res = 0, n = hours.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((hours[i] + hours[j]) % 24 == 0) {
                res++;
            }
        }
    }
    return res;
}
