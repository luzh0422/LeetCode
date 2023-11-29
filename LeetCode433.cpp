//
// Created by 陆泽辉 on 2022/5/7.
//

#include "LeetCode433.h"
#include <queue>

int LeetCode433::minMutation(string start, string end, vector<string> &bank) {
    int n = bank.size(), endIndex = -1, startIndex = -1;
    for (int i = 0; i < n; i++) {
        if (bank[i] == start) {
            startIndex = i;
        }
        if (bank[i] == end) {
            endIndex = i;
        }
    }
    if (endIndex == -1) {
        return -1;
    }
    if (startIndex == -1) {
        bank.push_back(start);
        startIndex = n;
        n = n + 1;
    }
    vector<vector<int>> g(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (mutation(bank[i], bank[j]) == 1) {
                g[i][j] = 1;
                g[j][i] = 1;
            }
        }
    }
    vector<int> dist(n, 0);
    queue<int> q;
    q.push(startIndex);
    while (!q.empty()) {
        auto node = q.front();
        if (node == endIndex) {
            return dist[endIndex];
        }
        q.pop();
        auto distance = dist[node];
        for (int i = 0; i < n; i++) {
            if (g[node][i] == 1 && dist[i] == 0) {
                dist[i] = distance + 1;
                q.push(i);
            }
        }
    }
    return -1;
}

int LeetCode433::mutation(string s1, string s2) {
    int ret = 0;
    for (int i = 0; i < 8; i++) {
       if (s1[i] != s2[i]) {
           ret++;
       }
    }
    return ret;
}
