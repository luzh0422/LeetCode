//
// Created by luzehui on 2023/10/27.
//

#include "LeetCode2558.h"
#include <queue>

long long LeetCode2558::pickGifts(vector<int> &gifts, int k) {
    priority_queue<int, vector<int>, less<int>> pq;
    for (auto gift : gifts) {
        pq.push(gift);
    }
    while (k > 0) {
        auto curr = pq.top();
        pq.pop();
        curr = sqrt(curr);
        pq.push(curr);
        k--;
    }
    long long ans = 0ll;
    while (!pq.empty()) {
        auto gift = pq.top();
        pq.pop();
        ans += gift;
    }
    return ans;
}
