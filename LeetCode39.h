//
// Created by luzehui on 2024/4/21.
//

#ifndef LEETCODE_LEETCODE39_H
#define LEETCODE_LEETCODE39_H

#include <vector>

using namespace std;

class LeetCode39 {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target);

private:
    void combinationSum(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& curr, int currTotal, int startIndex);
};


#endif //LEETCODE_LEETCODE39_H
