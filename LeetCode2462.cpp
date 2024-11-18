//
// Created by luzehui on 2024/5/7.
//

#include "LeetCode2462.h"
#include <queue>

long long LeetCode2462::totalCost(vector<int> &costs, int k, int candidates) {
//    long long res = 0ll;
//    for (int i = 0; i < k; i++) {
//        if (candidates < costs.size()) {
//            auto minElement1 = min_element(costs.begin(), costs.begin() + candidates);
//            auto minElement2 = min_element(costs.end() - candidates, costs.end());
//            if (*minElement1 < * minElement2) {
//                res += *minElement1;
//                costs.erase(minElement1);
//            } else {
//                res += *minElement2;
//                costs.erase(minElement2);
//            }
//        } else {
//            auto minElement = min_element(costs.begin(), costs.end());
//            res += *minElement;
//            costs.erase(minElement);
//        }
//    }
//    return res;

    long long res = 0ll;
    priority_queue<int, vector<int>, greater<int>> pq1, pq2;
    int n = costs.size(), left = 0, right = n - 1;
    for (int i = 0; i < candidates && i < n / 2; i++) {
        pq1.push(costs[left++]);
        pq2.push(costs[right--]);
    }
    if (n == 1) {
        pq1.push(costs[left++]);
    }
    for (int i = 0; i < k; i++) {
        int num1 = pq1.empty() ? INT_MAX : pq1.top();
        int num2 = pq2.empty() ? INT_MAX : pq2.top();
        if (num1 <= num2) {
            res += num1;
            pq1.pop();
            if (left <= right) {
                pq1.push(costs[left++]);
            }
        } else {
            res += num2;
            pq2.pop();
            if (left <= right) {
                pq2.push(costs[right--]);
            }
        }
    }
    return res;
}
