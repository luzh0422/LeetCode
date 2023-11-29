//
// Created by 陆泽辉 on 2023/9/12.
//

#include "LeetCode1462.h"
#include <set>
#include <queue>

vector<bool> LeetCode1462::checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries) {
    vector<vector<int>> outDegrees(numCourses);
    vector<int> inDegrees(numCourses);
    vector<set<int>> pre(numCourses);
    for (auto &v : prerequisites) {
        int v1 = v[0], v2 = v[1];
        outDegrees[v1].push_back(v2);
        inDegrees[v2]++;
    }

    queue<int> q;
    /**
     * 这些节点相当于没有前序依赖；
     */
    for (int i = 0; i < numCourses; i++) {
        if (inDegrees[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int course = q.front();
        q.pop();
        for (auto next : outDegrees[course]) {
            inDegrees[next]--;
            pre[next].insert(pre[course].begin(), pre[course].end());
            pre[next].insert(course);
            if (inDegrees[next] == 0) {
                q.push(next);
            }
        }
    }
    vector<bool> res;
    for (auto q : queries) {
        if (pre[q[1]].find(q[0]) != pre[q[1]].end()) {
            res.push_back(true);
        } else {
            res.push_back(false);
        }
    }
    return res;
}
