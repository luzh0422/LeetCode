//
// Created by 陆泽辉 on 2023/2/19.
//

#include "LeetCode1792.h"
#include <queue>

double LeetCode1792::maxAverageRatio(vector<vector<int>> &classes, int extraStudents) {
    auto cmp = [](vector<int> &v1, vector<int> &v2) -> bool {
        int num1 = v1[0], num2 = v1[1];
        int num3 = v2[0], num4 = v2[1];
        return (num4 + 1) * num4 * (num2 - num1) < (num2 + 1) * num2 * (num4 - num3);
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
    int n = classes.size();
    for (int i = 0; i < n; i++) {
        pq.push(classes[i]);
    }
    for (int i = 0; i < extraStudents; i++) {
        auto v = pq.top();
        pq.pop();
        int num1 = v[0], num2 = v[1];
        num1++;
        num2++;
        pq.push({num1, num2});
    }
    double total = 0.0f;
    while (!pq.empty()) {
        auto v = pq.top();
        pq.pop();
        int num1 = v[0], num2 = v[1];
        total += double(num1) / double(num2);
    }
    return total / double(n);
}
