//
// Created by luzehui on 2023/11/14.
//

#include "LeetCode1334.h"

int LeetCode1334::findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {
    pair<int, int> ans(0x3f3f3f3f, -1);
    vector<vector<int>> mp(n, vector<int>(n ,0x3f3f3f3f / 2));
    for (auto &edge : edges) {
        int from = edge[0], to = edge[1], weight = edge[2];
        mp[from][to] = mp[to][from] = weight;
    }
    for (int k = 0; k < n; ++k) {
        mp[k][k] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (mp[i][j] <= distanceThreshold) {
                cnt++;
            }
        }
        if (cnt <= ans.first) {
            ans = {cnt, i};
        }
    }
    return ans.second;
}
