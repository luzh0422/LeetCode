//
// Created by luzh on 2021/12/3.
//

#include "Solution1005.h"

#include <queue>

int Solution1005::largestSumAfterKNegations(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        pq.push(nums[i]);
        ans += nums[i];
    }
    for (int i = 0; i < k; i++) {
        int curr = pq.top();
        pq.pop();
        ans -= curr;
        curr = -curr;
        ans += curr;
        pq.push(curr);
    }
    return ans;
}
