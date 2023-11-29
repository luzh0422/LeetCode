//
// Created by 陆泽辉 on 2023/9/10.
//

#include "LeetCode210.h"
#include <queue>

vector<int> LeetCode210::findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> inDegrees(numCourses, 0);
    vector<vector<int>> outDegrees(numCourses, vector<int>{});
    for (auto prerequisity : prerequisites) {
        inDegrees[prerequisity[0]]++;
        outDegrees[prerequisity[1]].push_back(prerequisity[0]);
    }
    queue<int> q;
    vector<int> res;
    int target = 0;
    for (int i = 0; i < numCourses; i++) {
        if (inDegrees[i] == 0) {
            q.push(i);
            target++;
        }
    }
    while (!q.empty()) {
        auto curr = q.front();
        res.push_back(curr);
        q.pop();
        auto outDegree = outDegrees[curr];
        for (int i = 0; i < outDegree.size(); i++) {
            inDegrees[outDegree[i]]--;
            if (inDegrees[outDegree[i]] == 0) {
                q.push(outDegree[i]);
                target++;
            }
        }
    }
    if (target < numCourses) {
        return {};
    }
    return res;
}
