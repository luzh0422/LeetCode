//
// Created by 陆泽辉 on 2022/4/27.
//

#ifndef LEETCODE_LEETCODE417_H
#define LEETCODE_LEETCODE417_H

#include <vector>

using namespace std;

class LeetCode417 {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights);

private:
//    bool dfs(pair<int, int> currPos, pair<int, int> target, vector<vector<int>>& heights, vector<vector<int>>& visits, vector<vector<int>>& oceans, int m, int n);
    void dfs(pair<int, int> currPos, vector<vector<int>>& heights, vector<vector<int>>& oceans, int m, int n);
};


#endif //LEETCODE_LEETCODE417_H
