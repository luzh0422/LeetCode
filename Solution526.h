//
// Created by luzh on 2021/8/16.
//

#ifndef LEETCODE_SOLUTION526_H
#define LEETCODE_SOLUTION526_H

#include <vector>

using namespace std;

class Solution526 {
public:
    int countArrangement(int n);

private:
    void backtrack(int index, int n, int& ans, vector<int>& visit, vector<vector<int>>& matrix);
};


#endif //LEETCODE_SOLUTION526_H
