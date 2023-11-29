//
// Created by 陆泽辉 on 2022/5/23.
//

#ifndef LEETCODE_LEETCODE675_H
#define LEETCODE_LEETCODE675_H

#include <vector>

using namespace std;

class LeetCode675 {
public:
    int cutOffTree(vector<vector<int>>& forest);

private:
    int  bfs(vector<vector<int>> &forest, int start, int end, int m, int n);
};


#endif //LEETCODE_LEETCODE675_H
