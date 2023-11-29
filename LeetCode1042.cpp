//
// Created by 陆泽辉 on 2023/4/15.
//

#include "LeetCode1042.h"

vector<int> LeetCode1042::gardenNoAdj(int n, vector<vector<int>> &paths) {
    vector<int> res(n, -1);
    vector<vector<int>> graph(n, vector<int>{});
    for (auto path : paths) {
        graph[path[0] - 1].emplace_back(path[1] - 1);
        graph[path[1] - 1].emplace_back(path[0] - 1);
    }
    for (int i = 0; i < n; i++) {
        auto g = graph[i];
        if (g.empty()) {
            res[i] = 1;
            continue;
        }
        uint8_t tag = 0x00;
        for (int i = 0; i < g.size(); i++) {
            if (res[g[i]] != -1) {
                tag |= (1 << (res[g[i]] - 1));
            }
        }
        if ((0x01 & tag) == 0) {
            res[i] = 1;
        } else if ((0x02 & tag) == 0) {
            res[i] = 2;
        } else if ((0x04 & tag) == 0) {
            res[i] = 3;
        } else {
            res[i] = 4;
        }

    }
    return res;
}
