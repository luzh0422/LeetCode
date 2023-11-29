//
// Created by 陆泽辉 on 2022/12/19.
//

#include "LeetCode1971.h"
#include <stack>

bool LeetCode1971::validPath(int n, vector<vector<int>> &edges, int source, int destination) {
    vector<vector<int>> paths(n, vector<int>());
    for (auto edge : edges) {
        paths[edge[0]].push_back(edge[1]);
        paths[edge[1]].push_back(edge[0]);
    }
    vector<int> visits(n, 0);
    visits[source] = 1;
    stack<int> stk;
    stk.push(source);
    while (!stk.empty()) {
        auto curr = stk.top();
        stk.pop();
        auto path = paths[curr];
        for (int i = 0; i < path.size(); i++) {
            if (!visits[path[i]]) {
                if (path[i] == destination) {
                    return true;
                }
                stk.push(path[i]);
                visits[path[i]] = 1;
            }
        }
    }
    return false;
}
