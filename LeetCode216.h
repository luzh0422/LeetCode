//
// Created by luzehui on 2024/4/21.
//

#ifndef LEETCODE_LEETCODE216_H
#define LEETCODE_LEETCODE216_H

#include <vector>

using namespace std;

class LeetCode216 {
public:
    vector<vector<int>> combinationSum3(int k, int n);

private:
    void combinationSum3(int k, int n, vector<vector<int>>& res, vector<int>& curr, int currTotal, int start);
};


#endif //LEETCODE_LEETCODE216_H
