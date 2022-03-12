//
// Created by luzh on 2021/10/6.
//

#include "Solution414.h"

#include <queue>

int Solution414::thirdMax(vector<int> &nums) {
    std::priority_queue<int, vector<int>, less<int>> priorityQueue;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        priorityQueue.push(nums[i]);
    }
    if (n < 3) {
        return priorityQueue.top();
    } else {
        int max = priorityQueue.top();
        while (priorityQueue.top() == max && !priorityQueue.empty()) {
            priorityQueue.pop();
        }
        int second = priorityQueue.top();
        while (priorityQueue.top() == second && !priorityQueue.empty()) {
            priorityQueue.pop();
        }
        if (priorityQueue.empty()) {
            return max;
        } else {
            return priorityQueue.top();
        }
    }
}
