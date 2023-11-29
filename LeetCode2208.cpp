//
// Created by 陆泽辉 on 2023/7/25.
//

#include "LeetCode2208.h"
#include <queue>
#include <numeric>

int LeetCode2208::halveArray(vector<int> &nums) {
    priority_queue<double, vector<double>, less<double>> pq(nums.begin(), nums.end());
    double halfTotal = accumulate(nums.begin(), nums.end(), 0.0) / 2.0f;
    double temp = 0.0;
    int res = 0;
    while (temp < halfTotal) {
        auto curr = pq.top();
        pq.pop();
        temp += curr / 2;
        pq.push(curr / 2);
        res++;
    }
    return res;
}
