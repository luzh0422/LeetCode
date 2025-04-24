//
// Created by luzehui on 25-1-26.
//

#ifndef LEETCODE_LEETCODE40_H
#define LEETCODE_LEETCODE40_H

#include <vector>
#include <unordered_set>

using namespace std;

class LeetCode40 {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target);

private:
    void combinationSum2(vector<int>& candidates, int target, int total, vector<int>& curr, vector<vector<int>>& res, int index);
};


#endif //LEETCODE_LEETCODE40_H
