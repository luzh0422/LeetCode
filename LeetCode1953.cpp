//
// Created by luzehui on 2024/5/16.
//

#include "LeetCode1953.h"
#include <queue>
#include <numeric>

long long LeetCode1953::numberOfWeeks(vector<int> &milestones) {
//    priority_queue<int, vector<int>, less<int>> pq;
//    for (auto milestone : milestones) {
//        pq.push(milestone);
//    }
//    int res = 0;
//    while (!pq.empty()) {
//        int value1 = pq.top();
//        pq.pop();
//        if (pq.empty()) {
//            res++;
//            break;
//        }
//        int value2 = pq.top();
//        pq.pop();
//        res += 2;
//        res += value2 * 2;
//        if (value1 != value2) {
//            pq.push(value1 - value2);
//        }
//    }
//    return res;
    long long maxEle = *max_element(milestones.begin(), milestones.end());
    long long total = std::accumulate(milestones.begin(), milestones.end(), 0ll);
    if (maxEle > total - maxEle + 1) {
        return (total - maxEle) * 2;
    }
    return total;
}
