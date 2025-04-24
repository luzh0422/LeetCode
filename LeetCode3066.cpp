//
// Created by luzehui on 25-1-15.
//

#include "LeetCode3066.h"
#include <queue>

int LeetCode3066::minOperations(vector<int> &nums, int k) {
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (auto num : nums) {
        pq.push(num);
    }
    int res = 0;
    while (pq.size() > 1) {
        long long first = pq.top();
        pq.pop();
        if (first >= k) {
            break;
        }
        long long second = pq.top();
        pq.pop();
        res++;
        pq.push(first * 2 + second);
    }
    return res;
}
