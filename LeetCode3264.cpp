//
// Created by luzehui on 24-12-13.
//

#include "LeetCode3264.h"
#include <queue>

using namespace std;

vector<int> LeetCode3264::getFinalState(vector<int> &nums, int k, int multiplier) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    const int MOD = 1e9 + 7;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        pq.emplace(nums[i], i);
    }
    for (int i = 0; i < k; i++) {
        auto num = pq.top();
        pq.pop();
        int value = num.first, index = num.second;
        value %= MOD;
        value *= multiplier;
        value %= MOD;
        pq.emplace(value, index);
    }
    while (!pq.empty()) {
        auto num = pq.top();
        pq.pop();
        int value = num.first, index = num.second;
        nums[index] = value;
    }
    return nums;
}
