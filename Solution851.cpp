//
// Created by luzh on 2021/12/15.
//

#include "Solution851.h"

vector<int> Solution851::loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) {
    int n = quiet.size();
    graph.resize(n);
    for (int i = 0; i < n; i++) {
        graph[i].resize(n + 1, 0);
    }
    int richerN = richer.size();
    for (int i = 0; i < richerN; i++) {
        int x = richer[i][0], y = richer[i][1];
        graph[y][x] = 1;
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int temp = i;
        dfs(i, quiet, temp);
        ans[i] = temp;
    }
    return ans;
}

/**
 * 因为很多点会重复查找，因此可以做剪枝来处理；
 * @param node
 * @param quiet
 * @param ans
 */
void Solution851::dfs(int node, vector<int> &quiet, int& ans) {
    int currQuiet = quiet[node];
    int n = quiet.size();
    if (quiet[node] < quiet[ans]) {
        ans = node;
    }
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1) {
            dfs(i, quiet, ans);
        }
    }
}
