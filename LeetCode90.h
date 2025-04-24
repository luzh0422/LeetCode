//
// Created by luzehui on 25-2-5.
//

#ifndef LEETCODE_LEETCODE90_H
#define LEETCODE_LEETCODE90_H

#include <vector>

using namespace std;

class LeetCode90 {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums);

private:
    void backtrack(vector<int>& nums, vector<int>& currArr, vector<vector<int>>& res, int index);
};


#endif //LEETCODE_LEETCODE90_H
