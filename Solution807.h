//
// Created by luzh on 2021/12/13.
//

#ifndef LEETCODE_SOLUTION807_H
#define LEETCODE_SOLUTION807_H

#include <vector>

using namespace std;

class Solution807 {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid);

private:
    vector<int> maxRow;
    vector<int> maxColumn;
};


#endif //LEETCODE_SOLUTION807_H
