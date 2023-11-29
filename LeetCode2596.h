//
// Created by 陆泽辉 on 2023/9/13.
//

#ifndef LEETCODE_LEETCODE2596_H
#define LEETCODE_LEETCODE2596_H

#include <vector>

using namespace std;

class LeetCode2596 {
public:
    bool checkValidGrid(vector<vector<int>>& grid);
private:
    bool dfs(vector<vector<int>>& grid, int curr, int row, int column);
};


#endif //LEETCODE_LEETCODE2596_H
