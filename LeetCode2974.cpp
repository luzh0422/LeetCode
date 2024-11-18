//
// Created by luzehui on 2024/7/12.
//

#include "LeetCode2974.h"
#include <queue>

vector<int> LeetCode2974::numberGame(vector<int> &nums) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto num : nums) {
        pq.push(num);
    }
    vector<int> arr{};
    while (!pq.empty()) {
        int num1 = pq.top();
        pq.pop();
        int num2 = pq.top();
        pq.pop();
        arr.push_back(num2);
        arr.push_back(num1);
    }
    return arr;
}
