//
// Created by luzehui on 25-2-15.
//

#ifndef LEETCODE_LEETCODE1706_H
#define LEETCODE_LEETCODE1706_H

#include <vector>

using namespace std;

class LeetCode1706 {
public:
    vector<int> findBall(vector<vector<int>>& grid);

private:
    int findBall(vector<vector<int>>& grid, vector<vector<int>>& cache, int row, int col, int m, int n);
};


#endif //LEETCODE_LEETCODE1706_H
