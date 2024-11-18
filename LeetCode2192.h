//
// Created by luzehui on 2024/4/6.
//

#ifndef LEETCODE_LEETCODE2192_H
#define LEETCODE_LEETCODE2192_H

#include <vector>
#include <set>

using namespace std;

class LeetCode2192 {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges);

private:
    set<int> getAncestorsHelp(int n, int curr, vector<vector<int>>& res, vector<vector<int>>& graph, vector<int>& visits);
};


#endif //LEETCODE_LEETCODE2192_H
