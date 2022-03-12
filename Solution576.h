//
// Created by luzh on 2021/8/15.
//

#ifndef LEETCODE_SOLUTION576_H
#define LEETCODE_SOLUTION576_H

#include <vector>

using namespace std;

class Solution576 {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn);

private:
    int findPaths(vector<vector<int>>& matrix, int m, int n, int maxMove, int currRow, int currColumn);
};


#endif //LEETCODE_SOLUTION576_H
