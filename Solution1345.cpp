//
// Created by luzh on 2022/1/21.
//

#include "Solution1345.h"
#include <queue>
#include <unordered_map>

struct Graph {
    int distance = INT_MAX;
    int index = 0;
};

/**
 * 广度优先遍历，但是超时了；应该是构建图的流程有问题；
 * @param arr
 * @return
 */
int Solution1345::minJumps(vector<int> &arr) {
    int n = arr.size();
    vector<Graph* > g;
    unordered_map<int, vector<int>> um;
    for (int i = 0; i < n; i++) {
        g.push_back(new Graph());
        g[i]->index = i;
        if (um.count(arr[i])) {
            um[arr[i]].push_back(i);
        } else {
            um.insert(unordered_map<int, vector<int>>::value_type(arr[i], {}));
        }
    }
    queue<Graph*> q;
    q.push(g[0]);
    g[0]->distance = 0;
    while (!q.empty()) {
        Graph* curr = q.front();
        q.pop();
        if (curr->index == n - 1) {
            return curr->distance;
        }
        if (curr->index != 0 && g[curr->index - 1]->distance == INT_MAX) {
            g[curr->index - 1]->distance = curr->distance + 1;
            q.push(g[curr->index - 1]);
        }
        if (g[curr->index + 1]->distance == INT_MAX) {
            g[curr->index + 1]->distance = curr->distance + 1;
            q.push(g[curr->index + 1]);
        }
        auto nodes = um[arr[curr->index]];
        for (auto node: nodes) {
            if (g[node]->distance == INT_MAX) {
                g[node]->distance = curr->distance + 1;
                q.push(g[node]);
            }
        }
        um[arr[curr->index]].clear();
    }
    return -1;
}
