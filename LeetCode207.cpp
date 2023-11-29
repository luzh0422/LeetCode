//
// Created by 陆泽辉 on 2023/9/9.
//

#include "LeetCode207.h"
#include <queue>

bool LeetCode207::canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> outDegrees(numCourses, vector<int>{});
    vector<int> inDegrees(numCourses, 0);
    for (int i = 0; i < prerequisites.size(); i++) {
        auto prerequisity = prerequisites[i];
        outDegrees[prerequisity[1]].push_back(prerequisity[0]);
        inDegrees[prerequisity[0]]++;
    }
    int target = 0;
    queue<int> curr{};
    for (int i = 0; i < numCourses; i++) {
        if (inDegrees[i] == 0) {
            curr.push(i);
            target++;
            if (target == numCourses)
                return true;
        }
    }
    while (!curr.empty()) {
        auto outDegree = outDegrees[curr.front()];
        curr.pop();
        for (int i = 0; i < outDegree.size(); i++) {
            inDegrees[outDegree[i]]--;
            if (inDegrees[outDegree[i]] == 0) {
                curr.push(outDegree[i]);
                target++;
                if (target == numCourses) {
                    return true;
                }
            }
        }
    }
    return false;
}
