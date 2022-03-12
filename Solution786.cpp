//
// Created by luzh on 2021/11/29.
//

#include "Solution786.h"

#include <queue>

vector<int> Solution786::kthSmallestPrimeFraction(vector<int> &arr, int k) {
    int n  = arr.size();
    auto cmp = [&](const pair<int, int>& p1, const pair<int, int>& p2) -> bool {
        return arr[p1.first] * arr[p2.second] > arr[p2.first] * arr[p1.second];
    };
    /**
     * 存储分子分母的index；
     */
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
    /**
     * 因为arr[0] / arr[i] < arr[1] / arr[i] < arr[2] / arr[i] < arr[3] / arr[i] < ... < arr[i - 1] / arr[i];
     * 所以先在最小堆中存放arr[0] / arr[i];
     */
    for (int i = 1; i < n; i++) {
        q.emplace(0, i);
    }
    for (int i = 0; i < k; i++) {
        auto [first, second] = q.top();
        q.pop();
        if (first + 1 < second) {
            q.emplace(first + 1, second);
        }
    }
    return {arr[q.top().first], arr[q.top().second]};
}
