//
// Created by 陆泽辉 on 2023/2/11.
//

#include "LeetCode2335.h"
#include <queue>

int LeetCode2335::fillCups(vector<int> &amount) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < 3; i++) {
        if (amount[i] != 0) {
            pq.push(amount[i]);
        }
    }
    int res = 0;
    while (!pq.empty()) {
        res++;
        int first = pq.top();
        pq.pop();
        int second = 1;
        if (!pq.empty()) {
            second = pq.top();
            pq.pop();
        }
        first--;
        second--;
        if (first != 0) {
            pq.push(first);
        }
        if (second != 0) {
            pq.push(second);
        }
    }
    return res;
}
