//
// Created by 陆泽辉 on 2022/7/1.
//

#ifndef LEETCODE_LEETCODE241_H
#define LEETCODE_LEETCODE241_H

#include <vector>
#include <string>

using namespace std;

class LeetCode241 {
public:
    vector<int> diffWaysToCompute(string expression);

private:
    void backtrack(vector<int>& nums, vector<char>& operators, vector<int>& ret);
};


#endif //LEETCODE_LEETCODE241_H
