//
// Created by luzh on 2021/8/25.
//

#include "Solution797.h"

vector<vector<int>> Solution797::allPathsSourceTarget(vector<vector<int>> &graph) {
    vector<int> curr = {0};
    vector<vector<int>> ans = {};
    int target = graph.size() - 1;
    allPathsSourceTarget(graph, curr, ans, target);
    return ans;
}

void Solution797::allPathsSourceTarget(vector<vector<int>> &graph, vector<int> &curr, vector<vector<int>> &ans, int target) {
    int currNode = curr.back();
    if (currNode == target) {
        ans.push_back(curr);
        return;
    }
    for (auto edge: graph[currNode]) {
        curr.push_back(edge);
        allPathsSourceTarget(graph, curr, ans, target);
        curr.pop_back();
    }
    return;
}
