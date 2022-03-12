//
// Created by luzh on 2021/8/5.
//

#include "Solution802.h"

#include <queue>

/**
 * 1. 出度为0的顶点为安全节点；
 * 2. 只指向安全顶点的顶点是安全顶点；
 * 通过反向构图后，拓普排序计算；
 * @param graph
 * @return
 */
vector<int> Solution802::eventualSafeNodes(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<vector<int>> rg(n);
    vector<int> inDegree(n, 0);
    for (int i = 0; i < n; i++) {
        int temp = graph[i].size();
        for (int j = 0; j < temp; j++) {
            int y = graph[i][j];
            rg[y].push_back(i);
        }
        inDegree[i] = temp;
    }
    std::queue<int> q;
    for (int i = 0; i < inDegree.size(); i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i = 0; i < rg[node].size(); i++) {
            inDegree[rg[node][i]]--;
            if (inDegree[rg[node][i]] == 0) {
                q.push(rg[node][i]);
            }
        }
    }
    vector<int> ans = {};
    for (int i = 0; i < inDegree.size(); i++) {
        if (inDegree[i] == 0) {
            ans.push_back(i);
        }
    }
    return ans;
}
