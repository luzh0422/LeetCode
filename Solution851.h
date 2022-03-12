//
// Created by luzh on 2021/12/15.
//

#ifndef LEETCODE_SOLUTION851_H
#define LEETCODE_SOLUTION851_H

#include <vector>

using namespace std;

class Solution851 {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet);

private:
    vector<vector<int>> graph;
    void dfs(int node, vector<int>& quiet, int& ans);
};


#endif //LEETCODE_SOLUTION851_H
