//
// Created by luzehui on 2023/10/17.
//

#include "LeetCode2530.h"
#include <queue>

long long LeetCode2530::maxKelements(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, less<int>> pq;
    for (auto num : nums) {
        pq.push(num);
    }
    long long ans = 0ll;
    for (int i = 0; i < k; i++) {
        auto top = pq.top();
        pq.pop();
        ans += top;
        top = (top + 2) / 3;
        pq.push(top);
    }
    return ans;
}
