//
// Created by luzehui on 2024/11/14.
//

#ifndef LEETCODE_LEETCODE3249_H
#define LEETCODE_LEETCODE3249_H

#include <vector>

using namespace std;

class LeetCode3249 {
public:
    int countGoodNodes(vector<vector<int>>& edges);

private:
    int dfs(vector<vector<int>>& graph, vector<vector<int>>& subTreeNodes, int currNode, int lastNode);
};


#endif //LEETCODE_LEETCODE3249_H
