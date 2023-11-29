//
// Created by 陆泽辉 on 2022/10/16.
//

#include "LeetCode886.h"

bool LeetCode886::possibleBipartition(int n, vector<vector<int>> &dislikes) {
    vector<int> colors(n + 1, 0);
    vector<vector<int>> graph(n + 1);
    for (auto& dislike : dislikes) {
        graph[dislike[0]].push_back(dislike[1]);
        graph[dislike[1]].push_back(dislike[0]);
    }
    for (int i = 1; i <= n; i++) {
        if (colors[i] == 0 && !dfs(i, 1, colors, graph)) {
            return false;
        }
    }
    return true;
}

bool LeetCode886::dfs(int index, int newColor, vector<int> &colors, vector<vector<int>> &graph) {
    colors[index] = newColor;
    auto edge = graph[index];
    for (auto& nextnode : edge) {
        if (colors[nextnode] && colors[nextnode] == colors[index]) {
            return false;
        }
        if (!colors[nextnode] && !dfs(nextnode, 3 ^ newColor, colors, graph)) {
            return false;
        }
    }
    return true;
}
