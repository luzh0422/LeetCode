//
// Created by luzehui on 2023/12/5.
//

#include "LeetCode2477.h"
#include <functional>

long long LeetCode2477::minimumFuelCost(vector<vector<int>> &roads, int seats) {
    int n = roads.size();
    vector<vector<int>> graph(n + 1);
    for (auto& road : roads) {
        graph[road[0]].push_back(road[1]);
        graph[road[1]].push_back(road[0]);
    }
    long long res = 0;
    function<int(int, int)> dfs = [&](int curr, int fa) -> int {
        int peopleSum = 1;
        for (auto ne : graph[curr]) {
            if (ne != fa) {
                int peopleCnt = dfs(ne, curr);
                peopleSum += peopleCnt;
                res += (peopleCnt + seats - 1) / seats;
            }
        }
        return peopleSum;
    };
    dfs(0, -1);
    return res;
}
