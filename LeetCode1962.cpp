//
// Created by luzehui on 2023/12/23.
//

#include "LeetCode1962.h"

#include <queue>

int LeetCode1962::minStoneSum(vector<int> &piles, int k) {
    priority_queue<int, vector<int>, less<int>> pq;
    for (auto pile : piles) {
        pq.push(pile);
    }
    for (int i = 0; i < k; i++) {
        int val = pq.top();
        pq.pop();
        val = (val + 1) / 2;
        pq.push(val);
    }
    int res = 0;
    while (!pq.empty()) {
        res += pq.top();
        pq.pop();
    }
    return res;
}
