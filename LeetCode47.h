//
// Created by luzehui on 25-2-6.
//

#ifndef LEETCODE_LEETCODE47_H
#define LEETCODE_LEETCODE47_H

#include <vector>

using namespace std;

class LeetCode47 {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums);

private:
    void backtrack(vector<int>& nums, vector<int>& curr, vector<int>& tag, vector<vector<int>>& res);
};


#endif //LEETCODE_LEETCODE47_H
