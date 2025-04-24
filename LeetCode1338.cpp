//
// Created by luzehui on 24-12-15.
//

#include "LeetCode1338.h"
#include <unordered_map>
#include <queue>

int LeetCode1338::minSetSize(vector<int> &arr) {
    int n = arr.size();
    unordered_map<int, int> cache;
    for (int i = 0; i < n; i++) {
        cache[arr[i]] += 1;
    }
    priority_queue<int, vector<int>, less<int>> pq;
    for (auto iter = cache.begin(); iter != cache.end(); iter++) {
        pq.emplace(iter->second);
    }
    int res = 0, count = 0;
    while (!pq.empty()) {
        res++;
        count += pq.top();
        pq.pop();
        if (count * 2 >= n) {
            return res;
        }
    }
    return res;
}
