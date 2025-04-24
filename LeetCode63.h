//
// Created by luzehui on 25-2-9.
//

#ifndef LEETCODE_LEETCODE63_H
#define LEETCODE_LEETCODE63_H

#include <vector>

using namespace std;

class LeetCode63 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);

private:
    int backtrack(vector<vector<int>>& obstacleGrid, int row, int col, int m, int n, vector<vector<int>>& cache);
};


#endif //LEETCODE_LEETCODE63_H
