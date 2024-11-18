//
// Created by luzehui on 2024/11/14.
//

#include "LeetCode3249.h"

int LeetCode3249::countGoodNodes(vector<vector<int>> &edges) {
    int n = edges.size();
    vector<vector<int>> graph(n + 1, vector<int>{});
    for (auto &edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    vector<vector<int>> subTreeNodes(n + 1, vector<int>{});
    dfs(graph, subTreeNodes, 0, -1);
    int res = 0;
    for (auto &subTreeNode : subTreeNodes) {
        bool tag = true;
        int subTreeNodeSize = subTreeNode.size();
        for (int i = 0; i < subTreeNodeSize - 1; i++) {
            if (subTreeNode[i] != subTreeNode[i + 1]) {
                tag = false;
                break;
            }
        }
        if (tag) {
            res++;
        }
    }
    return res;
}

int LeetCode3249::dfs(vector<vector<int>> &graph, vector<vector<int>> &subTreeNodes, int currNode, int lastNode) {
    int res = 1;
    vector<int> next = graph[currNode];
    for (int i = 0; i < next.size(); i++) {
        if (next[i] != lastNode) {
            int num = dfs(graph, subTreeNodes, next[i], currNode);
            subTreeNodes[currNode].push_back(num);
            res += num;
        }
    }
    return res;
}
