//
// Created by luzehui on 2024/8/27.
//

#include "LeetCode690.h"
#include <functional>

int LeetCode690::getImportance(vector<Employee *> employees, int id) {
    vector<vector<int>> graph(2001, vector<int>());
    vector<int> importances(2001, 0);
    for (auto& employee : employees) {
        graph[employee->id].insert(graph[employee->id].begin(), employee->subordinates.begin(), employee->subordinates.end());
        importances[employee->id] = employee->importance;
    }
    int res = 0;
    function<void(int)> dfs = [&](int curr) -> void {
        res += importances[curr];
        for (auto next : graph[curr]) {
            dfs(next);
        }
        return;
    };
    dfs(id);
    return res;
}
