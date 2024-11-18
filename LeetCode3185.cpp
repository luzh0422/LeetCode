//
// Created by luzehui on 2024/10/23.
//

#include "LeetCode3185.h"

long long LeetCode3185::countCompleteDayPairs(vector<int> &hours) {
    vector<int> records(24, 0);
    long long res = 0ll;
    size_t n = hours.size();
    for (size_t i = 0; i < n; i++) {
        int hour = hours[i] % 24;
        int delta = (24 - hour) % 24;
        res += records[delta];
        records[hour]++;
    }
    return res;
}
