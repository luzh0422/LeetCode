//
// Created by luzh on 2022/1/11.
//

#ifndef LEETCODE_SOLUTION1036_H
#define LEETCODE_SOLUTION1036_H

#include <vector>

using namespace std;

class Solution1036 {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target);

private:
    bool check(vector<int>& a, vector<int>& b);
};

#endif //LEETCODE_SOLUTION1036_H
