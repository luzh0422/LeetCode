//
// Created by 陆泽辉 on 2023/7/13.
//

#ifndef LEETCODE_LEETCODE931_H
#define LEETCODE_LEETCODE931_H

#include <vector>

using namespace std;

class LeetCode931 {
public:
    int minFallingPathSum(vector<vector<int>>& matrix);

private:
    int dfs(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp);
};


#endif //LEETCODE_LEETCODE931_H
