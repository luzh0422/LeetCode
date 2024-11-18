//
// Created by luzehui on 2023/12/7.
//

#include "LeetCode1466.h"
#include <unordered_set>
#include <functional>

int LeetCode1466::minReorder(int n, vector<vector<int>> &connections) {
    vector<vector<int>> undirectedGraph(n);
    vector<unordered_set<int>> directedGraph(n);
    for (auto& connection : connections) {
        undirectedGraph[connection[0]].push_back(connection[1]);
        undirectedGraph[connection[1]].push_back(connection[0]);
        directedGraph[connection[0]].insert(connection[1]);
    }
    int res = 0;
    function<void(int, int)> dfs = [&](int curr, int last) -> void {
        for (auto node : undirectedGraph[curr]) {
            if (node == last) {
                continue;
            }
            if (directedGraph[curr].count(node)) {
                res++;
            }
            dfs(node, curr);
        }
    };
    dfs(0, -1);
    return res;
}
