//
// Created by luzehui on 2024/4/6.
//

#include "LeetCode2192.h"
#include <set>

using namespace std;

vector<vector<int>> LeetCode2192::getAncestors(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n, vector<int>(n, -1));
    for (auto& edge : edges) {
        int start = edge[1], end = edge[0];
        graph[start][end] = 1;
    }
    vector<vector<int>> res(n, vector<int>());
    vector<int> visits(n, 0);
    for (int i = 0; i < n; i++) {
        if (visits[i] == 0) {
            getAncestorsHelp(n, i, res, graph, visits);
        }
    }
    return res;
}

set<int> LeetCode2192::getAncestorsHelp(int n, int curr, vector<vector<int>> &res, vector<vector<int>>& graph, vector<int>& visits) {
//    set<int> temp{};
//    if (visits[curr] == 1) {
//        return set<int>(res[curr].begin(), res[curr].end());
//    }
//    for (int i = 0; i < n; i++) {
//        if (graph[curr][i] != -1) {
//            set<int> nextRes =
//                    getAncestorsHelp(n, i, res, graph, visits);
//            temp.insert(i);
//            temp.insert(nextRes.begin(), nextRes.end());
//        }
//    }
//    if (visits[curr] == 0) {
//        vector<int> tempArr(temp.begin(), temp.end());
//        res[curr] = tempArr;
//    }
//    visits[curr] = 1;
//    return temp;
    return {};
}
