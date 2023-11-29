//
// Created by 陆泽辉 on 2022/7/23.
//

#include "LeetCodeOffer2115.h"
#include <unordered_set>
#include <queue>

bool LeetCodeOffer2115::sequenceReconstruction(vector<int> &nums, vector<vector<int>> &sequences) {
    int n = nums.size();
    vector<int> indegrees(n + 1);
    vector<unordered_set<int>> graph(n + 1, unordered_set<int>());
    for (vector<int>& sequence: sequences) {
        int m = sequence.size();
        for (int i = 0; i < m - 1; i++) {
            int firstNode = sequence[i];
            int secondNode = sequence[i + 1];
            if (!graph[firstNode].count(secondNode)) {
                indegrees[secondNode]++;
                graph[firstNode].insert(secondNode);
            }
        }
    }
    queue<int> q = {};
    for (int i = 1; i <= n; i++) {
        if (indegrees[i] == 0) {
            q.push(i);
            indegrees[i]--;
        }
        if (q.size() > 1) {
            return false;
        }
    }
    int index = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr != nums[index]) {
            return false;
        }
        index++;
        auto currPath = graph[curr];
        for (auto it = currPath.begin(); it != currPath.end(); it++) {
            indegrees[*it]--;
            if (indegrees[*it] == 0) {
                q.push(*it);
                indegrees[*it]--;
            }
            if (q.size() > 1) {
                return false;
            }
        }
    }
    if (index != n) {
        return false;
    }
    return true;
}
