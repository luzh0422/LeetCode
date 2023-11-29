//
// Created by 陆泽辉 on 2022/10/26.
//

#ifndef LEETCODE_LEETCODE934_H
#define LEETCODE_LEETCODE934_H

#include <vector>

using namespace std;

class LeetCode934 {
public:
    int shortestBridge(vector<vector<int>>& grid);

private:
    void constrctIsland(vector<vector<int>>& grid, vector<pair<int, int>>& island);
};


#endif //LEETCODE_LEETCODE934_H
