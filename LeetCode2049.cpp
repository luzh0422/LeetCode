//
// Created by luzh on 2022/3/11.
//

#include "LeetCode2049.h"


int LeetCode2049::countHighestScoreNodes(vector<int> &parents) {
    int n = parents.size();
    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < n; i++) {
        if (parents[i] != -1) {
            graph[parents[i]].push_back(i);
        }
    }
    vector<vector<int>> childrenVal(n, vector<int>(2, 0));
    getChildVal(graph, 0, childrenVal);
    long long maxVal = 0;
    int ret = 0;
    for (int i = 0; i < n; i++) {
        long long leftVal = childrenVal[i][0];
        long long rightVal = childrenVal[i][1];
        long long otherVal = n - leftVal - rightVal - 1;
        leftVal = leftVal == 0 ? 1 : leftVal;
        rightVal = rightVal == 0 ? 1 : rightVal;
        otherVal = otherVal == 0 ? 1 : otherVal;
        if (leftVal * rightVal * otherVal > maxVal) {
            ret = 1;
            maxVal = leftVal * rightVal * otherVal;
        } else if (leftVal * rightVal * otherVal == maxVal) {
            ret++;
        }
    }
    return ret;
}

int LeetCode2049::getChildVal(vector<vector<int>> &graph, int root, vector<vector<int>> &childrenVal) {
    if (graph[root].size() > 0) {
        int left = graph[root][0];
        int leftVal = getChildVal(graph, left, childrenVal);
        int rightVal = 0;
        if (graph[root].size() > 1) {
            int right = graph[root][1];
            rightVal = getChildVal(graph, right, childrenVal);
            childrenVal[root][1] = rightVal;
        }
        childrenVal[root][0] = leftVal;
        return leftVal + rightVal + 1;
    } else {
        return 1;
    }
}
