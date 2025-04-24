//
// Created by luzehui on 24-12-24.
//

#include "LeetCode1705.h"
#include <queue>

int LeetCode1705::eatenApples(vector<int> &apples, vector<int> &days) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int n = days.size(), day = 1, res = 0;
    for (int i = 0; i < n; i++) {
        if (apples[i] != 0) {
            pq.emplace(i + days[i], apples[i]);
        }
        if (!pq.empty()) {
            auto value = pq.top();
            pq.pop();
            while (value.first < day && !pq.empty()) {
                value = pq.top();
                pq.pop();
            }
            if (value.first >= day) {
                value.second--;
                res++;
                if (value.second > 0) {
                    pq.emplace(value.first, value.second);
                }
            }
        }
        day++;
    }
    while (!pq.empty()) {
        auto value = pq.top();
        pq.pop();
        while (value.first < day && !pq.empty()) {
            value = pq.top();
            pq.pop();
        }
        if (value.first >= day) {
            value.second--;
            res++;
            if (value.second > 0) {
                pq.emplace(value.first, value.second);
            }
        }
        day++;
    }
    return res;
}
